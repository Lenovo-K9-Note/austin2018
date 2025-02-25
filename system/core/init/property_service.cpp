/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "property_service.h"

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/poll.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <memory>
#include <queue>
#include <vector>

#include <sys/resource.h>
#include <private/android_filesystem_config.h>

#include <android-base/chrono_utils.h>
#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>
#include <bootimg.h>
#include <fs_mgr.h>
#include <selinux/android.h>
#include <selinux/label.h>
#include <selinux/selinux.h>

#include "init.h"
#include "util.h"

using android::base::Timer;

#define PERSISTENT_PROPERTY_DIR  "/data/property"
#define RECOVERY_MOUNT_POINT "/recovery"

namespace android {
namespace init {

static int persistent_properties_loaded = 0;

static int property_set_fd = -1;

//configure the country code for overseas version.by zhulei7 at 5/28/2018 start
#define LINE  79 //country number in LocaleSet[][]
#define ITEMS   (LINE*3)
static char LocaleSet[ITEMS][3]={
"ru","ru","RU",    /* Russia */
"ru","ru","RU",    /* Kazakhstan */
"ua","ru","UA",    /* Ukraine */
"tr","tr","TR",    /* Turkey */
"pl","en","US",    /* Poland */
"hu","en","US",    /* Hungary */
"ro","en","US",    /* Romania */
"bg","en","US",    /* Bulgaria */
"hr","en","US",    /* Croatia */
"sl","en","US",    /* Slovenia */
"sk","en","US",    /* Slovakia */
"cy","en","US",    /* Cyprus */
"rs","en","US",    /* Serbia */
"cz","en","GB",    /* Czech Republic */
"es","en","US",    /* Spain */
"ch","en","US",    /* Switzerland */
"pt","en","US",    /* Portugal */
"nl","en","US",    /* Netherlands */
"be","en","US",    /* Belgium */
"se","en","US",    /* Sweden */
"dk","en","US",    /* Denmark */
"lk","en","LK",    /* Sri Lanka */
"lk","en","LK",    /* Nepal */
"lk","en","LK",    /* Bangladesh*/
"fi","en","US",    /* Norway */
"ee","en","US",    /* Estonia */
"lv","en","US",    /* Latvia */
"lt","en","US",    /* Lithuania */
"is","en","US",    /* Iceland */
"eg","ar","EG",    /* Egypt */
"lb","ar","EG",    /* Lebanon */
"ma","en","US",    /* Morocco */
"za","en","US",    /* South Africa */
"tn","fr","FR",    /* Tunisia */
"mu","en","US",    /* Mauritius */
"mz","en","US",    /* Mozambique */
"il","iw","IL",    /* Israel */
"sa","ar","SA",    /* Saudi Arabia */
"ae","ar","AE",    /* United Arab Emirates */
"jo","ar","EG",    /* Jordan	Arabic */
"ke","en","KE",    /* Kenya */
"ng","en","US",    /* Nigeria */
"ug","en","US",    /* Uganda */
"gh","en","US",    /* Ghana */
"om","ar","OM",    /* Oman */
"om","ar","OM",    /* Qatar */
"om","ar","OM",    /* Kuwait */
"om","ar","OM",    /* Bahrain */
"ke","en","KE",    /* Tanzania */
"na","en","US",    /* Namibia */
"us","en","US",    /* United States of America */
"ca","en","US",    /* Canada */
"pa","es","US",    /* Panama */
"cr","es","US",    /* Costa Rica */
"ve","en","US",    /* Venezuela */
"pe","en","US",    /* Peru */
"uy","en","US",    /* Uruguay */
"ec","es","US",    /* Ecuador */
"co","es","US",    /* Colombia */
"mx","es","US",    /* Mexico */
"cl","es","US",    /* Chile */
"ar","es","US",    /* Argentina */
"au","en","AU",    /* Australia */
"nz","en","NZ",    /* New Zealand */
"jp","ja","JP",    /* Japanese */
"tw","zh","TW",    /* Taiwan Chinese */
"id","id","ID",    /* Indonesia */
"vn","vi","VN",    /* Vietnam */
"in","en","IN",    /* India */
"my","ms","MY",    /* Malaysia */
"th","th","TH",    /* Thailand */
"ph","en","US",    /* Philippines */
"sg","en","SG",    /* Singapore */
"hk","zh","HK",    /* Hong Kong */
"kr","ko","KR",    /* Korea */
"cn","zh","CN",    /* China */
"bo","es","US",    /* Bolivia */
"py","es","US",    /* Paraguay */
"br","pt","BR",    /* Brazil */
};
//configure the country code for overseas version.by zhulei7 at 5/28/2018 end

void property_init() {
    if (__system_property_area_init()) {
        LOG(ERROR) << "Failed to initialize property area";
        exit(1);
    }
}

static bool check_mac_perms(const std::string& name, char* sctx, struct ucred* cr) {

    if (!sctx) {
      return false;
    }

    if (!sehandle_prop) {
      return false;
    }

    char* tctx = nullptr;
    if (selabel_lookup(sehandle_prop, &tctx, name.c_str(), 1) != 0) {
      return false;
    }

    property_audit_data audit_data;

    audit_data.name = name.c_str();
    audit_data.cr = cr;

    bool has_access = (selinux_check_access(sctx, tctx, "property_service", "set", &audit_data) == 0);

    freecon(tctx);
    return has_access;
}

static int check_control_mac_perms(const char *name, char *sctx, struct ucred *cr)
{
    /*
     *  Create a name prefix out of ctl.<service name>
     *  The new prefix allows the use of the existing
     *  property service backend labeling while avoiding
     *  mislabels based on true property prefixes.
     */
    char ctl_name[PROP_VALUE_MAX+4];
    int ret = snprintf(ctl_name, sizeof(ctl_name), "ctl.%s", name);

    if (ret < 0 || (size_t) ret >= sizeof(ctl_name))
        return 0;

    return check_mac_perms(ctl_name, sctx, cr);
}

static void write_persistent_property(const char *name, const char *value)
{
    char tempPath[PATH_MAX];
    char path[PATH_MAX];
    int fd;

    snprintf(tempPath, sizeof(tempPath), "%s/.temp.XXXXXX", PERSISTENT_PROPERTY_DIR);
    fd = mkstemp(tempPath);
    if (fd < 0) {
        PLOG(ERROR) << "Unable to write persistent property to temp file " << tempPath;
        return;
    }
    write(fd, value, strlen(value));
    fsync(fd);
    close(fd);

    snprintf(path, sizeof(path), "%s/%s", PERSISTENT_PROPERTY_DIR, name);
    if (rename(tempPath, path)) {
        PLOG(ERROR) << "Unable to rename persistent property file " << tempPath << " to " << path;
        unlink(tempPath);
    }
}

bool is_legal_property_name(const std::string& name) {
    size_t namelen = name.size();

    if (namelen < 1) return false;
    if (name[0] == '.') return false;
    if (name[namelen - 1] == '.') return false;

    /* Only allow alphanumeric, plus '.', '-', '@', ':', or '_' */
    /* Don't allow ".." to appear in a property name */
    for (size_t i = 0; i < namelen; i++) {
        if (name[i] == '.') {
            // i=0 is guaranteed to never have a dot. See above.
            if (name[i-1] == '.') return false;
            continue;
        }
        if (name[i] == '_' || name[i] == '-' || name[i] == '@' || name[i] == ':') continue;
        if (name[i] >= 'a' && name[i] <= 'z') continue;
        if (name[i] >= 'A' && name[i] <= 'Z') continue;
        if (name[i] >= '0' && name[i] <= '9') continue;
        return false;
    }

    return true;
}

static uint32_t PropertySetImpl(const std::string& name, const std::string& value) {
    size_t valuelen = value.size();

    if (!is_legal_property_name(name)) {
        LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: bad name";
        return PROP_ERROR_INVALID_NAME;
    }

    if (valuelen >= PROP_VALUE_MAX) {
        LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                   << "value too long";
        return PROP_ERROR_INVALID_VALUE;
    }

    prop_info* pi = (prop_info*) __system_property_find(name.c_str());
    if (pi != nullptr) {
        // ro.* properties are actually "write-once".
        if (android::base::StartsWith(name, "ro.")) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "property already set";
            return PROP_ERROR_READ_ONLY_PROPERTY;
        }

        __system_property_update(pi, value.c_str(), valuelen);
    } else {
        int rc = __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
        if (rc < 0) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "__system_property_add failed";
            return PROP_ERROR_SET_FAILED;
        }
    }

    // Don't write properties to disk until after we have read all default
    // properties to prevent them from being overwritten by default values.
    if (persistent_properties_loaded && android::base::StartsWith(name, "persist.")) {
        write_persistent_property(name.c_str(), value.c_str());
    }
    property_changed(name, value);
    return PROP_SUCCESS;
}

typedef int (*PropertyAsyncFunc)(const std::string&, const std::string&);

struct PropertyChildInfo {
    pid_t pid;
    PropertyAsyncFunc func;
    std::string name;
    std::string value;
};

static std::queue<PropertyChildInfo> property_children;

static void PropertyChildLaunch() {
    auto& info = property_children.front();
    pid_t pid = fork();
    if (pid < 0) {
        LOG(ERROR) << "Failed to fork for property_set_async";
        while (!property_children.empty()) {
            property_children.pop();
        }
        return;
    }
    if (pid != 0) {
        info.pid = pid;
    } else {
        if (info.func(info.name, info.value) != 0) {
            LOG(ERROR) << "property_set_async(\"" << info.name << "\", \"" << info.value
                       << "\") failed";
        }
        exit(0);
    }
}

bool PropertyChildReap(pid_t pid) {
    if (property_children.empty()) {
        return false;
    }
    auto& info = property_children.front();
    if (info.pid != pid) {
        return false;
    }
    if (PropertySetImpl(info.name, info.value) != PROP_SUCCESS) {
        LOG(ERROR) << "Failed to set async property " << info.name;
    }
    property_children.pop();
    if (!property_children.empty()) {
        PropertyChildLaunch();
    }
    return true;
}

static uint32_t PropertySetAsync(const std::string& name, const std::string& value,
                                 PropertyAsyncFunc func) {
    if (value.empty()) {
        return PropertySetImpl(name, value);
    }

    PropertyChildInfo info;
    info.func = func;
    info.name = name;
    info.value = value;
    property_children.push(info);
    if (property_children.size() == 1) {
        PropertyChildLaunch();
    }
    return PROP_SUCCESS;
}

static int RestoreconRecursiveAsync(const std::string& name, const std::string& value) {
    return selinux_android_restorecon(value.c_str(), SELINUX_ANDROID_RESTORECON_RECURSE);
}

uint32_t property_set(const std::string& name, const std::string& value) {
    if (name == "selinux.restorecon_recursive") {
        return PropertySetAsync(name, value, RestoreconRecursiveAsync);
    }

    return PropertySetImpl(name, value);
}

class SocketConnection {
 public:
  SocketConnection(int socket, const struct ucred& cred)
      : socket_(socket), cred_(cred) {}

  ~SocketConnection() {
    close(socket_);
  }

  bool RecvUint32(uint32_t* value, uint32_t* timeout_ms) {
    return RecvFully(value, sizeof(*value), timeout_ms);
  }

  bool RecvChars(char* chars, size_t size, uint32_t* timeout_ms) {
    return RecvFully(chars, size, timeout_ms);
  }

  bool RecvString(std::string* value, uint32_t* timeout_ms) {
    uint32_t len = 0;
    if (!RecvUint32(&len, timeout_ms)) {
      return false;
    }

    if (len == 0) {
      *value = "";
      return true;
    }

    // http://b/35166374: don't allow init to make arbitrarily large allocations.
    if (len > 0xffff) {
      LOG(ERROR) << "sys_prop: RecvString asked to read huge string: " << len;
      errno = ENOMEM;
      return false;
    }

    std::vector<char> chars(len);
    if (!RecvChars(&chars[0], len, timeout_ms)) {
      return false;
    }

    *value = std::string(&chars[0], len);
    return true;
  }

  bool SendUint32(uint32_t value) {
    int result = TEMP_FAILURE_RETRY(send(socket_, &value, sizeof(value), 0));
    return result == sizeof(value);
  }

  int socket() {
    return socket_;
  }

  const struct ucred& cred() {
    return cred_;
  }

 private:
  bool PollIn(uint32_t* timeout_ms) {
    struct pollfd ufds[1];
    ufds[0].fd = socket_;
    ufds[0].events = POLLIN;
    ufds[0].revents = 0;
    while (*timeout_ms > 0) {
      Timer timer;
      int nr = poll(ufds, 1, *timeout_ms);
      uint64_t millis = timer.duration().count();
      *timeout_ms = (millis > *timeout_ms) ? 0 : *timeout_ms - millis;

      if (nr > 0) {
        return true;
      }

      if (nr == 0) {
        // Timeout
        break;
      }

      if (nr < 0 && errno != EINTR) {
        PLOG(ERROR) << "sys_prop: error waiting for uid " << cred_.uid << " to send property message";
        return false;
      } else { // errno == EINTR
        // Timer rounds milliseconds down in case of EINTR we want it to be rounded up
        // to avoid slowing init down by causing EINTR with under millisecond timeout.
        if (*timeout_ms > 0) {
          --(*timeout_ms);
        }
      }
    }

    LOG(ERROR) << "sys_prop: timeout waiting for uid " << cred_.uid << " to send property message.";
    return false;
  }

  bool RecvFully(void* data_ptr, size_t size, uint32_t* timeout_ms) {
    size_t bytes_left = size;
    char* data = static_cast<char*>(data_ptr);
    while (*timeout_ms > 0 && bytes_left > 0) {
      if (!PollIn(timeout_ms)) {
        return false;
      }

      int result = TEMP_FAILURE_RETRY(recv(socket_, data, bytes_left, MSG_DONTWAIT));
      if (result <= 0) {
        return false;
      }

      bytes_left -= result;
      data += result;
    }

    return bytes_left == 0;
  }

  int socket_;
  struct ucred cred_;

  DISALLOW_IMPLICIT_CONSTRUCTORS(SocketConnection);
};

static void handle_property_set(SocketConnection& socket,
                                const std::string& name,
                                const std::string& value,
                                bool legacy_protocol) {
  const char* cmd_name = legacy_protocol ? "PROP_MSG_SETPROP" : "PROP_MSG_SETPROP2";
  if (!is_legal_property_name(name)) {
    LOG(ERROR) << "sys_prop(" << cmd_name << "): illegal property name \"" << name << "\"";
    socket.SendUint32(PROP_ERROR_INVALID_NAME);
    return;
  }

  struct ucred cr = socket.cred();
  char* source_ctx = nullptr;
  getpeercon(socket.socket(), &source_ctx);

  if (android::base::StartsWith(name, "ctl.")) {
    if (check_control_mac_perms(value.c_str(), source_ctx, &cr)) {
      handle_control_message(name.c_str() + 4, value.c_str());
      if (!legacy_protocol) {
        socket.SendUint32(PROP_SUCCESS);
      }
    } else {
      LOG(ERROR) << "sys_prop(" << cmd_name << "): Unable to " << (name.c_str() + 4)
                 << " service ctl [" << value << "]"
                 << " uid:" << cr.uid
                 << " gid:" << cr.gid
                 << " pid:" << cr.pid;
      if (!legacy_protocol) {
        socket.SendUint32(PROP_ERROR_HANDLE_CONTROL_MESSAGE);
      }
    }
  } else {
    if (check_mac_perms(name, source_ctx, &cr)) {
      uint32_t result = property_set(name, value);
      if (!legacy_protocol) {
        socket.SendUint32(result);
      }
    } else {
      LOG(ERROR) << "sys_prop(" << cmd_name << "): permission denied uid:" << cr.uid << " name:" << name;
      if (!legacy_protocol) {
        socket.SendUint32(PROP_ERROR_PERMISSION_DENIED);
      }
    }
  }

  freecon(source_ctx);
}

static void handle_property_set_fd() {
    static constexpr uint32_t kDefaultSocketTimeout = 2000; /* ms */

    int s = accept4(property_set_fd, nullptr, nullptr, SOCK_CLOEXEC);
    if (s == -1) {
        return;
    }

    struct ucred cr;
    socklen_t cr_size = sizeof(cr);
    if (getsockopt(s, SOL_SOCKET, SO_PEERCRED, &cr, &cr_size) < 0) {
        close(s);
        PLOG(ERROR) << "sys_prop: unable to get SO_PEERCRED";
        return;
    }

    SocketConnection socket(s, cr);
    uint32_t timeout_ms = kDefaultSocketTimeout;

    uint32_t cmd = 0;
    if (!socket.RecvUint32(&cmd, &timeout_ms)) {
        PLOG(ERROR) << "sys_prop: error while reading command from the socket";
        socket.SendUint32(PROP_ERROR_READ_CMD);
        return;
    }

    switch (cmd) {
    case PROP_MSG_SETPROP: {
        char prop_name[PROP_NAME_MAX];
        char prop_value[PROP_VALUE_MAX];

        if (!socket.RecvChars(prop_name, PROP_NAME_MAX, &timeout_ms) ||
            !socket.RecvChars(prop_value, PROP_VALUE_MAX, &timeout_ms)) {
          PLOG(ERROR) << "sys_prop(PROP_MSG_SETPROP): error while reading name/value from the socket";
          return;
        }

        prop_name[PROP_NAME_MAX-1] = 0;
        prop_value[PROP_VALUE_MAX-1] = 0;

        handle_property_set(socket, prop_value, prop_value, true);
        break;
      }

    case PROP_MSG_SETPROP2: {
        std::string name;
        std::string value;
        if (!socket.RecvString(&name, &timeout_ms) ||
            !socket.RecvString(&value, &timeout_ms)) {
          PLOG(ERROR) << "sys_prop(PROP_MSG_SETPROP2): error while reading name/value from the socket";
          socket.SendUint32(PROP_ERROR_READ_DATA);
          return;
        }

        handle_property_set(socket, name, value, false);
        break;
      }

    default:
        LOG(ERROR) << "sys_prop: invalid command " << cmd;
        socket.SendUint32(PROP_ERROR_INVALID_CMD);
        break;
    }
}

static bool load_properties_from_file(const char *, const char *);

/*
 * Filter is used to decide which properties to load: NULL loads all keys,
 * "ro.foo.*" is a prefix match, and "ro.foo.bar" is an exact match.
 */
static void load_properties(char *data, const char *filter)
{
    char *key, *value, *eol, *sol, *tmp, *fn;
    size_t flen = 0;

    if (filter) {
        flen = strlen(filter);
    }

    sol = data;
    while ((eol = strchr(sol, '\n'))) {
        key = sol;
        *eol++ = 0;
        sol = eol;

        while (isspace(*key)) key++;
        if (*key == '#') continue;

        tmp = eol - 2;
        while ((tmp > key) && isspace(*tmp)) *tmp-- = 0;

        if (!strncmp(key, "import ", 7) && flen == 0) {
            fn = key + 7;
            while (isspace(*fn)) fn++;

            key = strchr(fn, ' ');
            if (key) {
                *key++ = 0;
                while (isspace(*key)) key++;
            }

            load_properties_from_file(fn, key);

        } else {
            value = strchr(key, '=');
            if (!value) continue;
            *value++ = 0;

            tmp = value - 2;
            while ((tmp > key) && isspace(*tmp)) *tmp-- = 0;

            while (isspace(*value)) value++;

            if (flen > 0) {
                if (filter[flen - 1] == '*') {
                    if (strncmp(key, filter, flen - 1)) continue;
                } else {
                    if (strcmp(key, filter)) continue;
                }
            }

            property_set(key, value);
        }
    }
}

// Filter is used to decide which properties to load: NULL loads all keys,
// "ro.foo.*" is a prefix match, and "ro.foo.bar" is an exact match.
static bool load_properties_from_file(const char* filename, const char* filter) {
    Timer t;
    std::string data;
    std::string err;
    if (!ReadFile(filename, &data, &err)) {
        PLOG(WARNING) << "Couldn't load property file: " << err;
        return false;
    }
    data.push_back('\n');
    load_properties(&data[0], filter);
    LOG(VERBOSE) << "(Loading properties from " << filename << " took " << t << ".)";
    return true;
}

static void load_persistent_properties() {
    persistent_properties_loaded = 1;

    std::unique_ptr<DIR, int(*)(DIR*)> dir(opendir(PERSISTENT_PROPERTY_DIR), closedir);
    if (!dir) {
        PLOG(ERROR) << "Unable to open persistent property directory \""
                    << PERSISTENT_PROPERTY_DIR << "\"";
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir.get())) != NULL) {
        if (strncmp("persist.", entry->d_name, strlen("persist."))) {
            continue;
        }
        if (entry->d_type != DT_REG) {
            continue;
        }

        // Open the file and read the property value.
        int fd = openat(dirfd(dir.get()), entry->d_name, O_RDONLY | O_NOFOLLOW);
        if (fd == -1) {
            PLOG(ERROR) << "Unable to open persistent property file \"" << entry->d_name << "\"";
            continue;
        }

        struct stat sb;
        if (fstat(fd, &sb) == -1) {
            PLOG(ERROR) << "fstat on property file \"" << entry->d_name << "\" failed";
            close(fd);
            continue;
        }

        // File must not be accessible to others, be owned by root/root, and
        // not be a hard link to any other file.
        if (((sb.st_mode & (S_IRWXG | S_IRWXO)) != 0) || sb.st_uid != 0 || sb.st_gid != 0 || sb.st_nlink != 1) {
            PLOG(ERROR) << "skipping insecure property file " << entry->d_name
                        << " (uid=" << sb.st_uid << " gid=" << sb.st_gid
                        << " nlink=" << sb.st_nlink << " mode=" << std::oct << sb.st_mode << ")";
            close(fd);
            continue;
        }

        char value[PROP_VALUE_MAX];
        int length = read(fd, value, sizeof(value) - 1);
        if (length >= 0) {
            value[length] = 0;
            property_set(entry->d_name, value);
        } else {
            PLOG(ERROR) << "Unable to read persistent property file " << entry->d_name;
        }
        close(fd);
    }
}

// persist.sys.usb.config values can't be combined on build-time when property
// files are split into each partition.
// So we need to apply the same rule of build/make/tools/post_process_props.py
// on runtime.
static void update_sys_usb_config() {
    bool is_debuggable = android::base::GetBoolProperty("ro.debuggable", false);
    std::string config = android::base::GetProperty("persist.sys.usb.config", "");
    if (config.empty()) {
        property_set("persist.sys.usb.config", is_debuggable ? "adb" : "none");
    } else if (is_debuggable && config.find("adb") == std::string::npos &&
               config.length() + 4 < PROP_VALUE_MAX) {
        config.append(",adb");
        property_set("persist.sys.usb.config", config);
    }
}

void property_load_boot_defaults() {
    if (!load_properties_from_file("/system/etc/prop.default", NULL)) {
        // Try recovery path
        if (!load_properties_from_file("/prop.default", NULL)) {
            // Try legacy path
            load_properties_from_file("/default.prop", NULL);
        }
    }
    load_properties_from_file("/odm/default.prop", NULL);
    load_properties_from_file("/vendor/default.prop", NULL);

    update_sys_usb_config();
}

static void load_override_properties() {
    if (ALLOW_LOCAL_PROP_OVERRIDE) {
        load_properties_from_file("/data/local.prop", NULL);
    }
}

static int check_rlim_action() {
 struct rlimit rl;
     bool debug_trace = android::base::GetBoolProperty("persist.debug.trace", false);

    if(debug_trace) {
        rl.rlim_cur = RLIM_INFINITY;
        rl.rlim_max = RLIM_INFINITY;
        if (setrlimit(RLIMIT_CORE, &rl) < 0) {
            PLOG(ERROR) << "could not enable core file generation";
        }
    }
    return 0;
}

//configure the country code for overseas version.by zhulei7 at 5/28/2018 start
static void setcc_init_action(int sel)
{
    int fd = -1;
    int length = 0;
    int count;
    char tmp[11] = {0};
    char CCode[3] = {0};
    int trytimes = 5;

    while(trytimes--){
        fd = open("/persist/flag/countrycode.txt", O_RDONLY);
        if(fd >= 0)
            break;
        else
            LOG(ERROR) << "[EASYIMAGE] open /persist/flag/countrycode.txt failed!";
    }

    if(fd < 0){
        LOG(ERROR) << "[EASYIMAGE] file[/persist/flag/countrycode.txt] not exist!! \n";
        return;
    }
    else {
        length = read(fd, CCode, 2);
        close(fd);

        if(length <= 0){
            LOG(ERROR) << "[EASYIMAGE] fail to read /persist/flag/countrycode.txt !!\n";
            return;
        }
    }

    LOG(ERROR) << "[EASYIMAGE] Have CCode is "<< CCode << "\n";
    if(CCode[0] != 0){
        for(count = 0; count < ITEMS; count = count + 3) {
            if(strncasecmp(CCode, LocaleSet[count], 2) == 0)  {
                LOG(ERROR) << "[EASYIMAGE] LocaleSet[" << count << "] " << LocaleSet[count] << ", " << LocaleSet[count+1] << ", " << LocaleSet[count+2] << ".\n";
                strncpy(tmp,LocaleSet[count + 1],2);
                strncat(tmp,"-",1);
                strncat(tmp,LocaleSet[count + 2],2);
                if(sel == 0){
                    property_set("ro.product.locale", tmp);
                    property_set("ro.product.locale.language", LocaleSet[count + 1]);
                    property_set("ro.product.locale.region", LocaleSet[count + 2]);
                } else {
                    property_set("persist.sys.language", LocaleSet[count + 1]);
                    property_set("persist.sys.country", LocaleSet[count + 2]);
                }
                break;
            }
        }
    }

    return;
}
//configure the country code for overseas version.by zhulei7 at 5/28/2018 end

/* When booting an encrypted system, /data is not mounted when the
 * property service is started, so any properties stored there are
 * not loaded.  Vold triggers init to load these properties once it
 * has mounted /data.
 */
void load_persist_props(void) {
    load_override_properties();
    /* Read persistent properties after all default values have been loaded. */
    load_persistent_properties();
    property_set("ro.persistent_properties.ready", "true");
    /*check for coredump*/
    check_rlim_action();
    //configure the country code for overseas version.by zhulei7 at 5/28/2018 start
    setcc_init_action(1);
    //configure the country code for overseas version.by zhulei7 at 5/28/2018 end
}

void load_recovery_id_prop() {
    std::unique_ptr<fstab, decltype(&fs_mgr_free_fstab)> fstab(fs_mgr_read_fstab_default(),
                                                               fs_mgr_free_fstab);
    if (!fstab) {
        PLOG(ERROR) << "unable to read default fstab";
        return;
    }

    fstab_rec* rec = fs_mgr_get_entry_for_mount_point(fstab.get(), RECOVERY_MOUNT_POINT);
    if (rec == NULL) {
        LOG(ERROR) << "/recovery not specified in fstab";
        return;
    }

    int fd = open(rec->blk_device, O_RDONLY);
    if (fd == -1) {
        PLOG(ERROR) << "error opening block device " << rec->blk_device;
        return;
    }

    boot_img_hdr hdr;
    if (android::base::ReadFully(fd, &hdr, sizeof(hdr))) {
        std::string hex = bytes_to_hex(reinterpret_cast<uint8_t*>(hdr.id), sizeof(hdr.id));
        property_set("ro.recovery_id", hex);
    } else {
        PLOG(ERROR) << "error reading /recovery";
    }

    close(fd);
}
/* Huaqin add for AUSTIN2018-241 by zhangyongxu at 2018/5/10 start */
std::string property_get(const char* name) {
        char value[PROP_VALUE_MAX] = {0};
        __system_property_get(name, value);
        return value;
}

static void set_serialno_property(const char *key) {
        std::string serialno;
        std::string serialno_err;
        const char* serialno_file_name = "/persist/.sn.bin";

#ifdef HQ_SUPPORT_BUILD_FACTORY
            property_set(key, "0123456789ABCDEF");
            LOG(INFO) << "HQ-L: In factory build, serialno = 0123456789ABCDEF";
            return;
#endif

        bool set_sn = ReadFile(serialno_file_name, &serialno, &serialno_err);
        LOG(INFO) << "HQ-L : (set_serialno_property serialno set_sn " << set_sn << ".)";

        if (set_sn) {
            serialno = serialno.substr(32,32);
            LOG(INFO) << "HQ-L: (set_serialno_property serialno " << serialno << ".)";
            property_set(key, serialno.c_str());
        } else {
            LOG(INFO) << "HQ-L: SN is null ,set default serialno! err :" << serialno_err.c_str();
            property_set(key, property_get("ro.boot.serialno").c_str());
        }
}
/* Huaqin add for AUSTIN2018-241 by zhangyongxu at 2018/5/10 end */

void load_system_props() {
    //configure the country code for overseas version.by zhulei7 at 5/28/2018 start
    setcc_init_action(0);
    //configure the country code for overseas version.by zhulei7 at 5/28/2018 end
    load_properties_from_file("/system/build.prop", NULL);
    load_properties_from_file("/odm/build.prop", NULL);
    load_properties_from_file("/vendor/build.prop", NULL);
    load_properties_from_file("/factory/factory.prop", "ro.*");
    load_recovery_id_prop();

/* Huaqin add for AUSTIN2018-241 by zhangyongxu at 2018/5/10 start */
    set_serialno_property("ro.serialno");
/* Huaqin add for AUSTIN2018-241 by zhangyongxu at 2018/5/10 end */
}

void start_property_service() {
    property_set("ro.property_service.version", "2");

    property_set_fd = CreateSocket(PROP_SERVICE_NAME, SOCK_STREAM | SOCK_CLOEXEC | SOCK_NONBLOCK,
                                   false, 0666, 0, 0, nullptr, sehandle);
    if (property_set_fd == -1) {
        PLOG(ERROR) << "start_property_service socket creation failed";
        exit(1);
    }

    listen(property_set_fd, 8);

    register_epoll_handler(property_set_fd, handle_property_set_fd);
}

}  // namespace init
}  // namespace android
