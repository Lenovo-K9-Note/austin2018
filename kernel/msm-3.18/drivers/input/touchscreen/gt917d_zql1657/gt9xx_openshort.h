/* drivers/input/touchscreen/gt9xx_shorttp.h
 *
 * 2010 - 2012 Goodix Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Version:1.0
 *      V1.0:2012/10/20
 */


#ifndef _GT9XX_OPEN_SHORT_H_
#define _GT9XX_OPEN_SHORT_H_
//#include "tpd.h"
#include "gt9xx.h"
#define CFG_GROUP_LEN(p_cfg_grp)  (sizeof(p_cfg_grp) / sizeof(p_cfg_grp[0]))

const u8 dsp_short[] = {
	0x02,0x09,0xac,0xbb,0x01,0x06,0x89,0x82,0x8a,0x83,0xe0,0x22,0x50,0x02,0xe7,0x22,
	0xbb,0xfe,0x02,0xe3,0x22,0x89,0x82,0x8a,0x83,0xe4,0x93,0x22,0xa3,0xf8,0xe0,0xc5,
	0xf0,0x25,0xf0,0xf0,0xe5,0x82,0x15,0x82,0x70,0x02,0x15,0x83,0xe0,0xc8,0x38,0xf0,
	0xe8,0x22,0xe8,0x8f,0xf0,0xa4,0xcc,0x8b,0xf0,0xa4,0x2c,0xfc,0xe9,0x8e,0xf0,0xa4,
	0x2c,0xfc,0x8a,0xf0,0xed,0xa4,0x2c,0xfc,0xea,0x8e,0xf0,0xa4,0xcd,0xa8,0xf0,0x8b,
	0xf0,0xa4,0x2d,0xcc,0x38,0x25,0xf0,0xfd,0xe9,0x8f,0xf0,0xa4,0x2c,0xcd,0x35,0xf0,
	0xfc,0xeb,0x8e,0xf0,0xa4,0xfe,0xa9,0xf0,0xeb,0x8f,0xf0,0xa4,0xcf,0xc5,0xf0,0x2e,
	0xcd,0x39,0xfe,0xe4,0x3c,0xfc,0xea,0xa4,0x2d,0xce,0x35,0xf0,0xfd,0xe4,0x3c,0xfc,
	0x22,0x75,0xf0,0x08,0x75,0x82,0x00,0xef,0x2f,0xff,0xee,0x33,0xfe,0xcd,0x33,0xcd,
	0xcc,0x33,0xcc,0xc5,0x82,0x33,0xc5,0x82,0x9b,0xed,0x9a,0xec,0x99,0xe5,0x82,0x98,
	0x40,0x0c,0xf5,0x82,0xee,0x9b,0xfe,0xed,0x9a,0xfd,0xec,0x99,0xfc,0x0f,0xd5,0xf0,
	0xd6,0xe4,0xce,0xfb,0xe4,0xcd,0xfa,0xe4,0xcc,0xf9,0xa8,0x82,0x22,0xb8,0x00,0xc1,
	0xb9,0x00,0x59,0xba,0x00,0x2d,0xec,0x8b,0xf0,0x84,0xcf,0xce,0xcd,0xfc,0xe5,0xf0,
	0xcb,0xf9,0x78,0x18,0xef,0x2f,0xff,0xee,0x33,0xfe,0xed,0x33,0xfd,0xec,0x33,0xfc,
	0xeb,0x33,0xfb,0x10,0xd7,0x03,0x99,0x40,0x04,0xeb,0x99,0xfb,0x0f,0xd8,0xe5,0xe4,
	0xf9,0xfa,0x22,0x78,0x18,0xef,0x2f,0xff,0xee,0x33,0xfe,0xed,0x33,0xfd,0xec,0x33,
	0xfc,0xc9,0x33,0xc9,0x10,0xd7,0x05,0x9b,0xe9,0x9a,0x40,0x07,0xec,0x9b,0xfc,0xe9,
	0x9a,0xf9,0x0f,0xd8,0xe0,0xe4,0xc9,0xfa,0xe4,0xcc,0xfb,0x22,0x75,0xf0,0x10,0xef,
	0x2f,0xff,0xee,0x33,0xfe,0xed,0x33,0xfd,0xcc,0x33,0xcc,0xc8,0x33,0xc8,0x10,0xd7,
	0x07,0x9b,0xec,0x9a,0xe8,0x99,0x40,0x0a,0xed,0x9b,0xfd,0xec,0x9a,0xfc,0xe8,0x99,
	0xf8,0x0f,0xd5,0xf0,0xda,0xe4,0xcd,0xfb,0xe4,0xcc,0xfa,0xe4,0xc8,0xf9,0x22,0xeb,
	0x9f,0xf5,0xf0,0xea,0x9e,0x42,0xf0,0xe9,0x9d,0x42,0xf0,0xe8,0x9c,0x45,0xf0,0x22,
	0xe8,0x60,0x0f,0xec,0xc3,0x13,0xfc,0xed,0x13,0xfd,0xee,0x13,0xfe,0xef,0x13,0xff,
	0xd8,0xf1,0x22,0xe8,0x60,0x0f,0xef,0xc3,0x33,0xff,0xee,0x33,0xfe,0xed,0x33,0xfd,
	0xec,0x33,0xfc,0xd8,0xf1,0x22,0xec,0xf0,0xa3,0xed,0xf0,0xa3,0xee,0xf0,0xa3,0xef,
	0xf0,0x22,0xa8,0x82,0x85,0x83,0xf0,0xd0,0x83,0xd0,0x82,0x12,0x01,0xa9,0x12,0x01,
	0xa9,0x12,0x01,0xa9,0x12,0x01,0xa9,0xe4,0x73,0xe4,0x93,0xa3,0xc5,0x83,0xc5,0xf0,
	0xc5,0x83,0xc8,0xc5,0x82,0xc8,0xf0,0xa3,0xc5,0x83,0xc5,0xf0,0xc5,0x83,0xc8,0xc5,
	0x82,0xc8,0x22,0xa4,0x25,0x82,0xf5,0x82,0xe5,0xf0,0x35,0x83,0xf5,0x83,0x22,0x90,
	0x50,0x96,0x74,0xaa,0xf0,0x90,0x41,0x83,0xe0,0x44,0x08,0xf0,0x7d,0x48,0x7f,0x01,
	0x12,0x12,0x20,0x90,0x42,0x07,0x74,0x0f,0xf0,0x90,0x42,0x06,0xe0,0x44,0x02,0xf0,
	0xe0,0x54,0xfe,0xf0,0x90,0x42,0x51,0x74,0x03,0xf0,0xc2,0xaf,0x12,0x14,0x43,0x12,
	0x0d,0x3f,0x12,0x14,0x19,0x90,0xbf,0xfe,0xe4,0xf0,0x12,0x0c,0xdc,0x90,0x42,0x3a,
	0xe4,0xf0,0xa3,0x04,0xf0,0x90,0x50,0x8b,0x74,0x14,0xf0,0x90,0x50,0x8a,0xf0,0x12,
	0x07,0x21,0x90,0x60,0x2f,0x74,0x07,0xf0,0x7f,0x3b,0x12,0x14,0x67,0x90,0x50,0x96,
	0xe0,0xb4,0xaa,0x03,0x00,0x80,0xf6,0x12,0x0a,0x51,0x90,0x88,0x04,0xe0,0x70,0x02,
	0xa3,0xe0,0x60,0x03,0xd3,0x80,0x01,0xc3,0x40,0x08,0x90,0x88,0x01,0x74,0x10,0xf0,
	0x80,0x75,0x90,0x88,0x04,0xe0,0xff,0xa3,0xe0,0x90,0x80,0x58,0xcf,0xf0,0xa3,0xef,
	0xf0,0x7b,0x6a,0x7d,0x02,0x7f,0x1d,0x7e,0x00,0x12,0x0a,0xe1,0xe4,0x90,0x88,0x00,
	0xf0,0x90,0x42,0x07,0x74,0x0f,0xf0,0x90,0x42,0x06,0xe0,0x44,0x02,0xf0,0xe0,0x44,
	0x01,0xf0,0xe4,0xff,0xef,0x25,0xe0,0x24,0xa1,0xf5,0x82,0xe4,0x34,0xa4,0xf5,0x83,
	0xe4,0xf0,0xa3,0xf0,0xef,0x25,0xe0,0x24,0x31,0xf5,0x82,0xe4,0x34,0xa5,0xf5,0x83,
	0xe4,0xf0,0xa3,0xf0,0x0f,0xbf,0x48,0xdc,0xe4,0x90,0x88,0x01,0xf0,0x12,0x04,0xb0,
	0x12,0x03,0x50,0x12,0x08,0xfb,0x90,0x88,0x00,0xe0,0x44,0x08,0xf0,0x12,0x08,0x0e,
	0x90,0x88,0x00,0xe0,0x44,0x80,0xf0,0x90,0x88,0x00,0x74,0x88,0xf0,0x90,0x41,0xef,
	0x74,0x0f,0xf0,0x90,0x41,0xee,0xe0,0x44,0x02,0xf0,0xe0,0xff,0x54,0x01,0xf4,0x54,
	0x01,0xfe,0xef,0x54,0xfe,0x4e,0xf0,0xe0,0xff,0x54,0x01,0xf4,0x54,0x01,0xfe,0xef,
	0x54,0xfe,0x4e,0xf0,0xe0,0x54,0xfd,0xf0,0x90,0x42,0x07,0x74,0x0f,0xf0,0x90,0x42,
	0x06,0xe0,0x44,0x02,0xf0,0xe0,0x54,0xfe,0xf0,0x70,0xfe,0x60,0xfc,0x60,0x40,0x70,
	0x3e,0x12,0x13,0xa8,0x12,0x13,0xc1,0x12,0x14,0x73,0xe4,0xff,0x12,0x14,0x36,0x12,
	0x13,0x8d,0x12,0x14,0x4f,0xe4,0xfb,0xfd,0xfc,0xff,0xfe,0x12,0x10,0xb4,0xe4,0xfb,
	0xfd,0xfc,0xff,0xfe,0x12,0x10,0x66,0xe4,0xfb,0xfd,0xfc,0xff,0xfe,0x12,0x11,0x35,
	0xe4,0xff,0xfe,0x12,0x12,0x7f,0x12,0x13,0xc1,0x12,0x13,0xa8,0x12,0x14,0x73,0x22,
	0xe4,0xf5,0x0b,0xf5,0x0c,0x90,0x42,0x5d,0xe0,0xf5,0x09,0x90,0x42,0x62,0xe0,0xf5,
	0x0a,0x12,0x0d,0x9f,0xc2,0x0b,0x12,0x12,0xd7,0xe4,0x90,0x88,0x03,0xf0,0xf5,0x08,
	0xe5,0x08,0x30,0xe0,0x03,0x02,0x04,0x93,0x74,0x0b,0x25,0x08,0x12,0x06,0xa8,0xe0,
	0x70,0x03,0x02,0x04,0x93,0x90,0x42,0x0f,0x74,0x0f,0xf0,0x90,0x42,0x0e,0x12,0x06,
	0x07,0xc2,0x08,0xad,0x08,0x90,0x88,0x03,0xe0,0x75,0xf0,0x41,0xa4,0x24,0xd2,0xf5,
	0x82,0xe5,0xf0,0x34,0xa0,0xaf,0x82,0xf5,0x0b,0x8f,0x0c,0xf5,0x83,0xe0,0x54,0x7f,
	0xf0,0xed,0x54,0x7f,0xff,0xe0,0x54,0x80,0x4f,0xf0,0xed,0xc3,0x13,0xfc,0x12,0x06,
	0x67,0x74,0x02,0xf0,0xed,0xc3,0x94,0x10,0x50,0x1a,0x90,0x32,0x46,0xc0,0x83,0xc0,
	0x82,0x74,0x01,0x7e,0x00,0xc8,0xed,0xc8,0x08,0x80,0x05,0xc3,0x33,0xce,0x33,0xce,
	0xd8,0xf9,0x80,0x1c,0x90,0x32,0x44,0xc0,0x83,0xc0,0x82,0xed,0x24,0xf0,0xff,0x74,
	0x01,0x7e,0x00,0xc8,0xef,0xc8,0x08,0x80,0x05,0xc3,0x33,0xce,0x33,0xce,0xd8,0xf9,
	0xff,0xe0,0x4e,0xfe,0xa3,0xe0,0x4f,0xff,0xd0,0x82,0xd0,0x83,0xee,0xf0,0xa3,0xef,
	0xf0,0xcf,0xec,0xcf,0x7d,0x01,0x12,0x0e,0xb8,0x12,0x06,0xf0,0xa3,0xee,0xf0,0xa3,
	0xef,0xf0,0x12,0x06,0xf0,0xa3,0xa3,0xa3,0xe5,0x08,0x12,0x06,0xc4,0xee,0xf0,0xa3,
	0xef,0xf0,0x90,0x32,0x44,0x12,0x01,0x92,0x00,0x00,0x00,0x00,0xc2,0x0b,0xe5,0x0c,
	0x24,0x03,0xf5,0x12,0xe4,0x35,0x0b,0xf5,0x11,0x85,0x08,0x13,0x12,0x0b,0x68,0xaf,
	0x0c,0xae,0x0b,0x12,0x0f,0xc1,0x12,0x06,0xf0,0x12,0x06,0x37,0xe5,0x08,0x25,0xe0,
	0x24,0xf5,0xf5,0x82,0xe4,0x34,0xa4,0x12,0x06,0x2a,0x12,0x06,0xf0,0x12,0x06,0x37,
	0xe5,0x08,0x25,0xe0,0x24,0xf7,0xf5,0x82,0xe4,0x34,0xa4,0x12,0x06,0x2a,0x30,0x08,
	0x09,0x12,0x05,0xfe,0x90,0x88,0x03,0xe0,0x04,0xf0,0xe5,0x08,0xc3,0x13,0x12,0x06,
	0x67,0xe4,0xf0,0x05,0x08,0xe5,0x08,0xc3,0x94,0x1d,0x50,0x03,0x02,0x03,0x70,0x90,
	0x42,0x5d,0xe5,0x09,0xf0,0x90,0x42,0x62,0xe5,0x0a,0x12,0x06,0x7a,0x02,0x12,0xab,
	0xe4,0xf5,0x0f,0xf5,0x10,0x90,0x42,0x5d,0xe0,0xf5,0x0a,0x90,0x42,0x62,0xe0,0xf5,
	0x0b,0x12,0x0d,0x9f,0xc2,0x0b,0x12,0x12,0xd7,0xe4,0x90,0x88,0x02,0xf0,0xf5,0x08,
	0x12,0x06,0xff,0x12,0x06,0x43,0xe0,0x70,0x03,0x02,0x05,0xd6,0xc2,0x08,0x12,0x06,
	0xff,0xff,0x12,0x06,0x58,0x74,0x02,0xf0,0x8f,0x0c,0x90,0x88,0x02,0xe0,0x75,0xf0,
	0x95,0xa4,0x24,0x60,0xf5,0x82,0xe5,0xf0,0x34,0x88,0xaf,0x82,0xf5,0x0f,0x8f,0x10,
	0xf5,0x83,0xe0,0x44,0x80,0xf0,0xe5,0x0c,0x54,0x7f,0xff,0xe0,0x54,0x80,0x4f,0xf0,
	0xaf,0x0c,0x12,0x05,0xef,0x12,0x07,0x06,0xa3,0xe5,0x0d,0xf0,0xa3,0xe5,0x0e,0xf0,
	0x12,0x07,0x06,0xe5,0x08,0x12,0x06,0x21,0xe5,0x0d,0xf0,0xe5,0x0e,0x12,0x06,0x82,
	0xf5,0x09,0xe5,0x08,0x24,0x01,0xff,0xe4,0x33,0xfe,0xc3,0xe5,0x09,0x9f,0xee,0x64,
	0x80,0xf8,0x74,0x80,0x98,0x50,0x0b,0x12,0x06,0x19,0xe4,0xf0,0xa3,0xf0,0x05,0x09,
	0x80,0xe0,0xe5,0x08,0x04,0xf5,0x09,0xe5,0x09,0xc3,0x94,0x2a,0x50,0x34,0xe5,0x09,
	0x12,0x06,0x3e,0xe0,0x60,0x28,0x12,0x05,0xef,0x12,0x06,0x19,0xe5,0x0d,0xf0,0xa3,
	0xe5,0x0e,0xf0,0xc3,0x90,0x88,0x05,0xe0,0x95,0x0e,0x90,0x88,0x04,0xe0,0x95,0x0d,
	0x50,0x09,0xd2,0x08,0x90,0x88,0x01,0xe0,0x44,0x01,0xf0,0x12,0x06,0x84,0x05,0x09,
	0x80,0xc5,0xd2,0x0b,0xe5,0x10,0x24,0x57,0xf5,0x12,0xe4,0x35,0x0f,0xf5,0x11,0x85,
	0x08,0x13,0x12,0x0b,0x68,0xaf,0x10,0xae,0x0f,0x12,0x0f,0x6b,0x12,0x07,0x06,0x12,
	0x06,0x37,0xe5,0x08,0x25,0xe0,0x24,0xa1,0xf5,0x82,0xe4,0x34,0xa4,0x12,0x06,0x2a,
	0x30,0x08,0x09,0x12,0x05,0xfe,0x90,0x88,0x02,0xe0,0x04,0xf0,0x12,0x06,0xff,0x24,
	0x00,0x12,0x06,0x69,0xe4,0xf0,0x05,0x08,0xe5,0x08,0xc3,0x94,0x2a,0x50,0x03,0x02,
	0x04,0xd0,0xe5,0x0a,0x12,0x06,0xf7,0xe5,0x0b,0x12,0x06,0x7a,0x02,0x12,0xab,0x12,
	0x0e,0x5d,0x8f,0x0c,0x7d,0x01,0x12,0x0e,0xb8,0x8e,0x0d,0x8f,0x0e,0x22,0x90,0x42,
	0x0b,0x74,0x0f,0xf0,0x90,0x42,0x0a,0xe0,0x44,0x02,0xf0,0xe0,0xff,0x54,0x01,0xf4,
	0x54,0x01,0xfe,0xef,0x54,0xfe,0x4e,0xf0,0x22,0x85,0x10,0x82,0x85,0x0f,0x83,0xe5,
	0x09,0xa3,0xa3,0xa3,0x75,0xf0,0x02,0x02,0x01,0xc3,0xf5,0x83,0xee,0xf0,0xa3,0xef,
	0xf0,0x22,0xe0,0xfc,0xa3,0xe0,0xfd,0xa3,0xe0,0xfe,0xa3,0xe0,0xff,0x22,0x90,0x11,
	0x85,0x93,0xff,0x24,0x29,0xf5,0x82,0xe4,0x34,0x80,0xf5,0x83,0x22,0x74,0x08,0x2c,
	0xf5,0x82,0xe4,0x34,0x88,0xf5,0x83,0x22,0x24,0x00,0xfd,0xe4,0x34,0x32,0xfc,0xed,
	0x64,0x03,0xf5,0x82,0x8c,0x83,0x22,0x24,0x2c,0xff,0xe4,0x34,0x32,0xfe,0xef,0x64,
	0x03,0xf5,0x82,0x8e,0x83,0x22,0xe0,0x90,0x42,0x62,0xf0,0x90,0x42,0x7d,0x74,0x02,
	0xf0,0x22,0xa3,0xf0,0x90,0x32,0x42,0xe4,0xf0,0xa3,0xf0,0x90,0x42,0x82,0xf0,0x22,
	0xee,0xf0,0xa3,0xef,0xf0,0xee,0x54,0x7f,0xfe,0xc3,0x90,0x88,0x52,0xe0,0x9f,0x90,
	0x88,0x51,0xe0,0x9e,0x22,0x74,0x0b,0x2f,0xf5,0x82,0xe4,0x34,0x80,0xf5,0x83,0x22,
	0xf5,0x82,0xe4,0x35,0x83,0xf5,0x83,0xe4,0xf0,0xa3,0xf0,0x22,0x85,0x12,0x82,0x85,
	0x11,0x83,0xe5,0x14,0x75,0xf0,0x02,0x02,0x01,0xc3,0x74,0x32,0x2c,0xf5,0x82,0xe4,
	0x34,0x88,0xf5,0x83,0x22,0xf8,0xeb,0x4f,0xff,0xea,0x4e,0xfe,0xe9,0x4d,0xfd,0xe8,
	0x4c,0xfc,0x22,0xe0,0xf8,0xa3,0xe0,0xf9,0xa3,0xe0,0xfa,0xa3,0xe0,0xfb,0xe8,0x22,
	0x85,0x0c,0x82,0x85,0x0b,0x83,0x22,0x90,0x42,0x5d,0xf0,0x90,0x42,0x62,0x22,0xe5,
	0x08,0x90,0x11,0x85,0x93,0x22,0x85,0x10,0x82,0x85,0x0f,0x83,0x22,0x25,0xe0,0x24,
	0x31,0xf5,0x82,0xe4,0x34,0xa5,0x22,0x25,0xe0,0x24,0x85,0xf5,0x82,0xe4,0x34,0xa5,
	0x22,0x90,0x40,0x13,0xe0,0x54,0xfd,0xf0,0xe0,0x54,0xfb,0xf0,0x90,0x30,0x10,0x74,
	0x0f,0xf0,0x90,0x30,0xaa,0xe0,0x54,0xf0,0x44,0x07,0xf0,0x90,0x42,0x7d,0x74,0x02,
	0xf0,0x90,0x42,0x82,0xe4,0xf0,0x90,0x32,0x42,0xf0,0xa3,0xf0,0xa3,0x12,0x01,0x92,
	0x15,0x55,0x55,0x55,0x90,0x30,0x15,0x74,0x01,0xf0,0x90,0x30,0x13,0x74,0x07,0xf0,
	0x90,0x30,0x0c,0x74,0x03,0xf0,0x90,0x42,0x5f,0x74,0x01,0xf0,0x90,0x30,0xab,0xe0,
	0x44,0x40,0xf0,0x90,0x30,0x06,0x74,0x0f,0xf0,0x90,0x30,0x0b,0xe0,0x54,0xf0,0xf0,
	0x90,0x30,0x1b,0x74,0x04,0xf0,0x90,0x30,0x11,0x74,0x1d,0x12,0x14,0x29,0x90,0x42,
	0x56,0xe4,0xf0,0x90,0x42,0x5a,0xf0,0x90,0x42,0x62,0x74,0x04,0xf0,0x90,0x42,0x77,
	0x74,0x2b,0xf0,0x90,0x30,0x1c,0xe4,0xf0,0x90,0x60,0x2f,0xe0,0x54,0xc7,0x44,0x08,
	0xf0,0xe0,0x54,0xf8,0xf0,0x90,0x37,0x33,0xe0,0x54,0xdf,0xf0,0x90,0x42,0x5b,0xe4,
	0xf0,0x90,0x42,0x60,0xf0,0xa3,0xf0,0x90,0x42,0x5e,0x04,0xf0,0x90,0x42,0x7a,0xf0,
	0x90,0x42,0x79,0xf0,0x90,0x42,0x7f,0xe4,0xf0,0x90,0x42,0x7e,0x04,0xf0,0x90,0x42,
	0x80,0xe0,0x54,0xdf,0xf0,0x90,0x37,0x33,0xe0,0x54,0xfb,0xf0,0xe0,0x44,0x01,0xf0,
	0xe0,0x44,0x02,0xf0,0x7f,0xfa,0x12,0x13,0xd9,0x7f,0x08,0x12,0x0f,0x12,0x7f,0x0b,
	0x12,0x0d,0xff,0x90,0x30,0x22,0xe4,0xf0,0x90,0x40,0x48,0x04,0xf0,0x22,0x90,0x42,
	0x5d,0xe0,0x90,0x80,0x86,0xf0,0x90,0x42,0x62,0xe0,0x90,0x80,0x87,0xf0,0x12,0x0d,
	0x9f,0xc2,0x0b,0x12,0x12,0xd7,0x12,0x06,0x7b,0xe4,0x90,0x80,0x84,0xf0,0x90,0x80,
	0x84,0xe0,0xff,0xc3,0x94,0x1e,0x40,0x03,0x02,0x08,0xdf,0xef,0x12,0x07,0x17,0x12,
	0x06,0xb5,0x12,0x06,0xa5,0xe0,0x70,0x03,0x02,0x08,0xd6,0x90,0x80,0x84,0xe0,0xa3,
	0xf0,0x90,0x32,0x44,0xc0,0x83,0xc0,0x82,0x12,0x06,0xe3,0xc0,0xe0,0xe9,0xc0,0xe0,
	0xe4,0x7f,0x01,0xfe,0xfd,0xfc,0x90,0x80,0x85,0xe0,0xf9,0xf8,0x12,0x01,0x73,0xd0,
	0xe0,0xf9,0xd0,0xe0,0x12,0x06,0xd5,0xd0,0x82,0xd0,0x83,0x12,0x01,0x86,0x90,0x42,
	0x81,0xe0,0x54,0x3f,0xf0,0x12,0x08,0xf0,0x90,0x80,0x88,0xee,0xf0,0xa3,0xef,0xf0,
	0x90,0x32,0x44,0x12,0x01,0x92,0x00,0x00,0x00,0x00,0x12,0x08,0xf0,0x90,0x80,0x8a,
	0xee,0xf0,0xfc,0xa3,0xef,0xf0,0x90,0x80,0x88,0x12,0x11,0xe8,0x90,0x80,0x8c,0x12,
	0x06,0x90,0x50,0x09,0x90,0x88,0x01,0xe0,0x44,0x08,0xf0,0x80,0x07,0xe4,0x90,0x80,
	0x8c,0xf0,0xa3,0xf0,0x90,0x80,0x8c,0xe0,0xfe,0xa3,0xe0,0xff,0x90,0x80,0x84,0xe0,
	0x12,0x07,0x17,0x12,0x06,0x2a,0x90,0x80,0x84,0xe0,0x04,0xf0,0x02,0x08,0x2e,0x90,
	0x80,0x86,0xe0,0x90,0x42,0x5d,0xf0,0x90,0x80,0x87,0x12,0x06,0x76,0x02,0x12,0xab,
	0x90,0x80,0x85,0xe0,0xc3,0x13,0xff,0x12,0x0b,0xee,0x22,0x90,0x42,0x5d,0xe0,0x90,
	0x80,0x86,0xf0,0x90,0x42,0x62,0xe0,0x90,0x80,0x87,0xf0,0x12,0x0d,0x9f,0xc2,0x0b,
	0x12,0x12,0xd7,0x90,0x42,0x7d,0x74,0x01,0xf0,0xe4,0x90,0x80,0x84,0xf0,0x90,0x80,
	0x84,0xe0,0xff,0xc3,0x94,0x2a,0x50,0x73,0xef,0x12,0x07,0x0d,0x12,0x06,0xb5,0xef,
	0x12,0x06,0x3e,0xe0,0x60,0x5c,0x12,0x0e,0x5d,0x90,0x80,0x85,0xef,0xf0,0x90,0x42,
	0x81,0xe0,0x54,0x3f,0xf0,0x12,0x0b,0xee,0x90,0x80,0x88,0xee,0xf0,0xef,0x12,0x06,
	0x82,0x90,0x80,0x85,0xe0,0xff,0x12,0x0b,0xee,0x90,0x80,0x8a,0xee,0xf0,0xfc,0xa3,
	0xef,0xf0,0x90,0x80,0x88,0x12,0x11,0xe8,0x90,0x80,0x8c,0x12,0x06,0x90,0x50,0x09,
	0x90,0x88,0x01,0xe0,0x44,0x08,0xf0,0x80,0x07,0xe4,0x90,0x80,0x8c,0xf0,0xa3,0xf0,
	0x90,0x80,0x8c,0xe0,0xfe,0xa3,0xe0,0xff,0x90,0x80,0x84,0xe0,0x12,0x07,0x0d,0x12,
	0x06,0x2a,0x90,0x80,0x84,0xe0,0x04,0xf0,0x02,0x09,0x1e,0x90,0x80,0x86,0xe0,0x90,
	0x42,0x5d,0xf0,0x90,0x80,0x87,0x12,0x06,0x76,0x02,0x12,0xab,0xc2,0xaf,0x12,0x14,
	0x43,0x78,0xff,0xe4,0xf6,0xd8,0xfd,0x90,0x80,0x00,0x7f,0x00,0x7e,0x50,0xe4,0xf0,
	0xa3,0xdf,0xfc,0xde,0xfa,0x75,0xa0,0xbe,0x75,0x89,0x00,0x75,0x81,0xff,0x02,0x0a,
	0x0c,0x02,0x01,0xcf,0xe4,0x93,0xa3,0xf8,0xe4,0x93,0xa3,0x40,0x03,0xf6,0x80,0x01,
	0xf2,0x08,0xdf,0xf4,0x80,0x29,0xe4,0x93,0xa3,0xf8,0x54,0x07,0x24,0x0c,0xc8,0xc3,
	0x33,0xc4,0x54,0x0f,0x44,0x20,0xc8,0x83,0x40,0x04,0xf4,0x56,0x80,0x01,0x46,0xf6,
	0xdf,0xe4,0x80,0x0b,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x90,0x13,0xef,0xe4,
	0x7e,0x01,0x93,0x60,0xbc,0xa3,0xff,0x54,0x3f,0x30,0xe5,0x09,0x54,0x1f,0xfe,0xe4,
	0x93,0xa3,0x60,0x01,0x0e,0xcf,0x54,0xc0,0x25,0xe0,0x60,0xa8,0x40,0xb8,0xe4,0x93,
	0xa3,0xfa,0xe4,0x93,0xa3,0xf8,0xe4,0x93,0xa3,0xc8,0xc5,0x82,0xc8,0xca,0xc5,0x83,
	0xca,0xf0,0xa3,0xc8,0xc5,0x82,0xc8,0xca,0xc5,0x83,0xca,0xdf,0xe9,0xde,0xe7,0x80,
	0xbe,0xe4,0xfe,0xfd,0xfc,0x12,0x06,0x4d,0xe0,0x2d,0xfd,0x0c,0xbc,0x2a,0xf6,0xe4,
	0xfc,0x12,0x06,0xca,0xe0,0x2d,0xfd,0x0c,0xbc,0x1e,0xf6,0xed,0x70,0x02,0x7e,0x01,
	0x90,0x88,0x50,0xe0,0x2d,0x60,0x02,0x7e,0x01,0xee,0x60,0x21,0xe4,0xfc,0x12,0x06,
	0x4d,0xec,0xf0,0xd3,0x94,0x19,0x40,0x06,0x12,0x06,0x4d,0xe0,0x04,0xf0,0x0c,0xbc,
	0x2a,0xec,0xe4,0xfc,0x12,0x06,0xca,0xec,0xf0,0x0c,0xbc,0x1e,0xf7,0x7c,0x2b,0x90,
	0x80,0x29,0xe4,0xf0,0xa3,0xdc,0xfc,0x7c,0x1e,0x90,0x80,0x0b,0xe4,0xf0,0xa3,0xdc,
	0xfc,0xe4,0xfc,0x12,0x06,0x4d,0xe0,0xff,0xc3,0x94,0x2b,0x50,0x09,0x74,0x29,0x2f,
	0x12,0x06,0x45,0x74,0x01,0xf0,0x0c,0xbc,0x2a,0xe9,0xe4,0xfc,0x12,0x06,0xca,0xe0,
	0xff,0xc3,0x94,0x1e,0x50,0x06,0x12,0x06,0xa5,0x74,0x01,0xf0,0x0c,0xbc,0x1e,0xec,
	0x22,0xd3,0x10,0xaf,0x01,0xc3,0xc0,0xd0,0x90,0x80,0x54,0xee,0xf0,0xa3,0xef,0xf0,
	0xa3,0xed,0xf0,0xa3,0xeb,0xf0,0x90,0x80,0x80,0x74,0x01,0xf0,0xa3,0x74,0x80,0xf0,
	0xa3,0x74,0x58,0xf0,0x7f,0xfe,0x7e,0xbf,0x12,0x11,0xaf,0xef,0x60,0xf6,0x90,0x80,
	0x56,0xe0,0x24,0xe3,0xff,0x90,0x80,0x83,0xf0,0x12,0x13,0x02,0x90,0x80,0x54,0xe0,
	0xff,0x12,0x13,0x02,0x90,0x80,0x55,0xe0,0xff,0x12,0x13,0x02,0x90,0x80,0x57,0xe0,
	0x80,0x1d,0x90,0x80,0x56,0xe0,0xff,0x14,0xf0,0xef,0x60,0x19,0x90,0x80,0x80,0xe0,
	0xfb,0xa3,0xe4,0x75,0xf0,0x01,0x12,0x00,0x1c,0xa9,0xf0,0xfa,0x12,0x00,0x03,0xff,
	0x12,0x13,0x02,0x80,0xdd,0x90,0x80,0x83,0xe0,0xf4,0xff,0x12,0x13,0x02,0x90,0xbf,
	0xfe,0xe4,0xf0,0xd0,0xd0,0x92,0xaf,0x22,0xe4,0xf5,0x14,0x12,0x06,0xbc,0xe4,0xf0,
	0xa3,0xf0,0x05,0x14,0xe5,0x14,0xb4,0x1e,0xf2,0xe4,0xf5,0x14,0x74,0x0b,0x25,0x14,
	0x12,0x06,0xa8,0xe0,0x60,0x5e,0x20,0x0b,0x06,0xe5,0x13,0x65,0x14,0x60,0x55,0x20,
	0x0b,0x0c,0xe5,0x14,0xc3,0x95,0x13,0x50,0x05,0xe5,0x14,0x30,0xe0,0x46,0xaf,0x14,
	0x12,0x10,0xf5,0x7d,0x01,0x12,0x0e,0xb8,0x12,0x06,0xbc,0xee,0xf0,0xa3,0xef,0xf0,
	0xc3,0x90,0x88,0x05,0xe0,0x9f,0x90,0x88,0x04,0xe0,0x9e,0x50,0x16,0xd2,0x08,0x90,
	0x88,0x01,0xe0,0xff,0x30,0x0b,0x04,0x7e,0x04,0x80,0x02,0x7e,0x02,0xef,0x4e,0x90,
	0x88,0x01,0xf0,0x90,0x42,0x7d,0xe0,0x54,0xfd,0xf0,0x90,0x32,0x44,0x12,0x01,0x92,
	0x00,0x00,0x00,0x00,0x05,0x14,0xe5,0x14,0xc3,0x94,0x1e,0x40,0x8f,0x22,0xef,0x54,
	0x0f,0xff,0x90,0x30,0x38,0xe0,0x54,0xf0,0x4f,0xf0,0xa3,0x74,0x01,0xf0,0x90,0x30,
	0x18,0x74,0xc0,0xf0,0xa3,0xe4,0xf0,0x90,0x80,0x0a,0x04,0xf0,0x90,0x88,0x06,0xe0,
	0xfe,0xa3,0xe0,0xff,0x12,0x13,0x2b,0x90,0x30,0x03,0xe4,0xf0,0x30,0xff,0xfd,0x90,
	0x30,0x03,0x74,0x01,0xf0,0x7f,0x96,0x12,0x13,0xd9,0xe4,0xf5,0x1b,0xf5,0x1c,0xfd,
	0x7c,0xc0,0x7b,0xc8,0xfa,0xeb,0x25,0xe0,0xff,0xea,0x33,0xfe,0xed,0x2f,0xf5,0x82,
	0xec,0x3e,0xf5,0x83,0xe0,0xa2,0xe7,0x13,0xfe,0xa3,0xe0,0x13,0x25,0x1c,0xf5,0x1c,
	0xee,0x35,0x1b,0xf5,0x1b,0x0b,0xbb,0x00,0x01,0x0a,0xba,0x01,0xd8,0xbb,0x08,0xd5,
	0xe5,0x1c,0xae,0x1b,0x78,0x05,0xce,0xa2,0xe7,0x13,0xce,0x13,0xd8,0xf8,0xf5,0x1c,
	0x8e,0x1b,0xff,0x22,0xcb,0xef,0xcb,0xca,0xee,0xca,0xe4,0xf5,0x0b,0xf5,0x0a,0xf5,
	0x09,0xf5,0x08,0x8b,0x82,0x8a,0x83,0xe4,0x93,0xff,0x60,0x47,0xc3,0x94,0x30,0x40,
	0x3b,0xef,0xd3,0x94,0x39,0x50,0x35,0xaf,0x0b,0xae,0x0a,0xad,0x09,0xac,0x08,0x78,
	0x04,0x12,0x01,0x73,0x8f,0x0b,0x8e,0x0a,0x8d,0x09,0x8c,0x08,0xe4,0x93,0x24,0xd0,
	0xff,0xe4,0x34,0xff,0xfe,0xe4,0xfc,0xfd,0xe5,0x0b,0x2f,0xf5,0x0b,0xe5,0x0a,0x3e,
	0xf5,0x0a,0xed,0x35,0x09,0xf5,0x09,0xec,0x35,0x08,0xf5,0x08,0x0b,0xbb,0x00,0x01,
	0x0a,0x80,0xb0,0xaf,0x0b,0xae,0x0a,0xad,0x09,0xac,0x08,0x22,0x7e,0x11,0x7f,0x73,
	0x12,0x0c,0x74,0x90,0x80,0x02,0x12,0x01,0x86,0x7e,0x11,0x7f,0x7c,0x12,0x0c,0x74,
	0x90,0x80,0x06,0x12,0x01,0x86,0x90,0x80,0x02,0x12,0x06,0x32,0x90,0x80,0x58,0x12,
	0x01,0x86,0x90,0x80,0x06,0x12,0x06,0x32,0x90,0x80,0x5c,0x12,0x01,0x86,0x7b,0xfa,
	0x7d,0x08,0x7f,0x01,0x7e,0x00,0x12,0x0a,0xe1,0x90,0x80,0x00,0xe0,0xfc,0xa3,0xe0,
	0xfd,0xec,0xff,0x90,0x80,0x58,0xe4,0xf0,0xa3,0xef,0xf0,0xcf,0xed,0xcf,0xa3,0xe4,
	0xf0,0xa3,0xef,0xf0,0x7b,0x5a,0x7d,0x04,0x7f,0x02,0x7e,0x00,0x02,0x0a,0xe1,0xae,
	0x2d,0xaf,0x2e,0xe4,0xfc,0xfd,0x7b,0xfe,0x7a,0x04,0xf9,0xf8,0x12,0x00,0x32,0x7b,
	0x00,0x7a,0xc2,0x79,0x01,0x78,0x00,0x12,0x00,0xbd,0x8f,0x0b,0x8e,0x0a,0x8d,0x09,
	0x8c,0x08,0xe4,0x78,0x00,0xf2,0xe4,0xff,0x7e,0x01,0xfd,0xfc,0xab,0x0b,0xaa,0x0a,
	0xa9,0x09,0xa8,0x08,0xc3,0x12,0x01,0x4f,0x40,0x1c,0xaf,0x0b,0xae,0x0a,0xad,0x09,
	0xac,0x08,0x78,0x01,0x12,0x01,0x60,0x8f,0x0b,0x8e,0x0a,0x8d,0x09,0x8c,0x08,0x78,
	0x00,0xe2,0x04,0xf2,0x80,0xd0,0x78,0x01,0xe5,0x0b,0xf2,0xe2,0x14,0xf2,0x22,0x90,
	0x42,0x56,0xe4,0xf0,0x90,0x42,0x5a,0xf0,0x90,0x42,0x60,0xf0,0xa3,0xf0,0x74,0x03,
	0x12,0x06,0xf7,0x04,0xf0,0x90,0x30,0x16,0xe4,0xf0,0xa3,0x74,0x75,0xf0,0x90,0x30,
	0x09,0x74,0x06,0xf0,0x90,0x42,0x7d,0x74,0x01,0xf0,0x90,0x30,0x1f,0xe0,0x44,0x01,
	0xf0,0x90,0x37,0x33,0xe0,0x44,0x04,0xf0,0x90,0x30,0x1e,0x74,0x05,0xf0,0x90,0x32,
	0x42,0xe4,0xf0,0xa3,0xf0,0xa3,0x12,0x01,0x92,0x00,0x00,0x00,0x00,0x90,0x42,0x82,
	0xe4,0xf0,0x90,0x42,0x5f,0x04,0xf0,0x90,0x42,0x81,0xe0,0x44,0x01,0xf0,0x22,0xef,
	0xb4,0x0c,0x00,0x50,0x4b,0x90,0x0e,0x0c,0xf8,0x28,0x28,0x73,0x02,0x0e,0x30,0x02,
	0x0e,0x30,0x02,0x0e,0x30,0x02,0x0e,0x30,0x02,0x0e,0x30,0x02,0x0e,0x30,0x02,0x0e,
	0x30,0x02,0x0e,0x36,0x02,0x0e,0x3c,0x02,0x0e,0x42,0x02,0x0e,0x48,0x02,0x0e,0x4e,
	0x7c,0x0f,0x7d,0xe0,0x80,0x1e,0x7c,0x07,0x7d,0xf0,0x80,0x18,0x7c,0x07,0x7d,0xf8,
	0x80,0x12,0x7c,0x07,0x7d,0xfc,0x80,0x0c,0x7c,0x07,0x7d,0xfe,0x80,0x06,0x80,0x00,
	0x7c,0x07,0x7d,0xff,0x90,0x37,0x26,0xec,0xf0,0xa3,0xed,0xf0,0x22,0xcd,0xef,0xcd,
	0xed,0xd3,0x94,0x0e,0x50,0x2d,0x90,0x32,0x42,0xc0,0x83,0xc0,0x82,0x74,0x01,0x7e,
	0x00,0xc8,0xed,0xc8,0x08,0x80,0x05,0xc3,0x33,0xce,0x33,0xce,0xd8,0xf9,0xff,0xe0,
	0x4e,0xfe,0xa3,0xe0,0x4f,0xff,0xd0,0x82,0xd0,0x83,0xee,0xf0,0xa3,0xef,0xf0,0xcf,
	0xed,0xcf,0x22,0xed,0xd3,0x94,0x1c,0x50,0x0b,0x90,0x42,0x82,0x74,0x02,0xf0,0xed,
	0x24,0xf2,0xff,0x22,0xed,0xd3,0x94,0x2a,0x50,0x0b,0x90,0x42,0x82,0x74,0x01,0xf0,
	0xed,0x24,0xe3,0xff,0x22,0x7f,0xff,0x22,0x8f,0x15,0x8d,0x16,0xe4,0xf5,0x17,0xf5,
	0x18,0xf5,0x19,0xf5,0x1a,0x12,0x0b,0xee,0x8e,0x17,0x8f,0x18,0xe5,0x16,0x60,0x0f,
	0x90,0x30,0x1e,0x74,0x86,0xf0,0xaf,0x15,0x12,0x0b,0xee,0x8e,0x19,0x8f,0x1a,0xd3,
	0xe5,0x18,0x95,0x1a,0xe5,0x19,0x64,0x80,0xf8,0xe5,0x17,0x64,0x80,0x98,0x40,0x0c,
	0xe5,0x18,0x95,0x1a,0xff,0xe5,0x17,0x95,0x19,0xfe,0x80,0x0b,0xc3,0xe5,0x1a,0x95,
	0x18,0xff,0xe5,0x19,0x95,0x17,0xfe,0x8e,0x17,0x8f,0x18,0x90,0x30,0x1e,0x74,0x05,
	0xf0,0x22,0xef,0xb4,0x09,0x00,0x50,0x46,0x90,0x0f,0x1f,0xf8,0x28,0x28,0x73,0x02,
	0x0f,0x3a,0x02,0x0f,0x3a,0x02,0x0f,0x3a,0x02,0x0f,0x3a,0x02,0x0f,0x40,0x02,0x0f,
	0x46,0x02,0x0f,0x4c,0x02,0x0f,0x52,0x02,0x0f,0x58,0x7c,0x00,0x7d,0xe0,0x80,0x22,
	0x7c,0x00,0x7d,0xf0,0x80,0x1c,0x7c,0x00,0x7d,0xf8,0x80,0x16,0x7c,0x00,0x7d,0xfc,
	0x80,0x10,0x7c,0x00,0x7d,0xfe,0x80,0x0a,0x7c,0x00,0x7d,0xff,0x80,0x04,0x7c,0x0f,
	0x7d,0xff,0x90,0x37,0x24,0xec,0xf0,0xa3,0xed,0xf0,0x22,0x8e,0x11,0x8f,0x12,0xe4,
	0xf5,0x13,0xf5,0x14,0xca,0xee,0xca,0xc9,0xef,0xc9,0x75,0x15,0x01,0x8a,0x16,0x89,
	0x17,0x8f,0x82,0x8e,0x83,0xe5,0x82,0x24,0x93,0x12,0x06,0xb0,0xff,0xab,0x15,0x05,
	0x17,0xe5,0x17,0xaa,0x16,0x70,0x02,0x05,0x16,0x14,0xf9,0x12,0x00,0x03,0x25,0x14,
	0xf5,0x14,0xe4,0x35,0x13,0xf5,0x13,0x0f,0xbf,0x95,0xe2,0xc3,0xe4,0x95,0x14,0xff,
	0xe4,0x95,0x13,0xfe,0xe5,0x12,0x24,0x93,0xf5,0x82,0xe4,0x35,0x11,0x12,0x06,0x2a,
	0x22,0x8e,0x0d,0x8f,0x0e,0xe4,0xf5,0x0f,0xf5,0x10,0xca,0xee,0xca,0xc9,0xef,0xc9,
	0x75,0x11,0x01,0x8a,0x12,0x89,0x13,0x8f,0x82,0x8e,0x83,0xe5,0x82,0x24,0x3f,0x12,
	0x06,0xb0,0xff,0xab,0x11,0x05,0x13,0xe5,0x13,0xaa,0x12,0x70,0x02,0x05,0x12,0x14,
	0xf9,0x12,0x00,0x03,0x25,0x10,0xf5,0x10,0xe4,0x35,0x0f,0xf5,0x0f,0x0f,0xbf,0x41,
	0xe2,0xc3,0xe4,0x95,0x10,0xff,0xe4,0x95,0x0f,0xfe,0xe5,0x0e,0x24,0x3f,0xf5,0x82,
	0xe4,0x35,0x0d,0x12,0x06,0x2a,0x22,0x90,0x60,0x01,0xe4,0xf0,0x90,0x60,0x00,0xf0,
	0x90,0x60,0x03,0xef,0xf0,0x90,0x60,0x02,0xed,0xf0,0x90,0x60,0x07,0x74,0x02,0xf0,
	0x90,0x60,0x06,0x14,0xf0,0x90,0x60,0x12,0x74,0xbd,0xf0,0xa3,0x74,0xc0,0xf0,0x90,
	0x60,0x22,0x74,0xbd,0xf0,0xa3,0x74,0xa0,0xf0,0x90,0x60,0x10,0xe4,0xf0,0xa3,0xf0,
	0x90,0x60,0x20,0xf0,0xa3,0xf0,0x90,0xbf,0xfd,0xf0,0xf5,0x30,0x90,0x60,0x01,0x04,
	0xf0,0x90,0x60,0x00,0xf0,0x22,0x8e,0x08,0x8f,0x09,0x8c,0x0a,0x8d,0x0b,0xd2,0xb5,
	0xc2,0xb2,0xc2,0xb1,0x7f,0x3b,0x12,0x14,0x36,0xe4,0xff,0x12,0x14,0x36,0xaf,0x08,
	0x12,0x14,0x36,0xaf,0x09,0x12,0x14,0x36,0x7f,0x08,0xd2,0xb0,0xc2,0xb0,0xdf,0xfa,
	0xc2,0xb5,0x85,0x0b,0x82,0x85,0x0a,0x83,0x7e,0x80,0x7f,0x04,0xd2,0xb0,0xa2,0xb4,
	0x33,0xa2,0xb7,0x33,0xc2,0xb0,0xdf,0xf4,0x12,0x14,0x73,0xde,0xed,0xdb,0xe9,0xc2,
	0xb0,0xd2,0xb1,0x22,0x8e,0x08,0x8f,0x09,0x8c,0x0a,0x8d,0x0b,0xd2,0xb5,0xc2,0xb2,
	0xc2,0xb1,0x7f,0x03,0x12,0x14,0x36,0xe4,0xff,0x12,0x14,0x36,0xaf,0x08,0x12,0x14,
	0x36,0xaf,0x09,0x12,0x14,0x36,0x85,0x0b,0x82,0x85,0x0a,0x83,0x7f,0x80,0x7e,0x08,
	0xd2,0xb0,0xa2,0xb4,0x33,0xc2,0xb0,0xde,0xf7,0x12,0x14,0x73,0xdf,0xf0,0xdb,0xec,
	0xc2,0xb0,0xd2,0xb1,0x22,0x8f,0x15,0xe5,0x15,0x30,0xe0,0x07,0x90,0x42,0x7d,0xe0,
	0x44,0x02,0xf0,0x90,0x32,0x44,0xc0,0x83,0xc0,0x82,0x12,0x06,0xe3,0xc0,0xe0,0xe9,
	0xc0,0xe0,0xe4,0x7f,0x01,0xfe,0xfd,0xfc,0xa9,0x15,0xc8,0xe9,0xc8,0x12,0x01,0x73,
	0xd0,0xe0,0xf9,0xd0,0xe0,0x12,0x06,0xd5,0xd0,0x82,0xd0,0x83,0x12,0x01,0x86,0xe5,
	0x15,0xc3,0x13,0xff,0x22,0x8e,0x08,0x8f,0x09,0x8c,0x0a,0x8d,0x0b,0xd2,0xb5,0xc2,
	0xb2,0x12,0x14,0x4f,0xc2,0xb1,0x7f,0x02,0x12,0x14,0x36,0xe4,0xff,0x12,0x14,0x36,
	0xaf,0x0a,0x12,0x14,0x36,0xaf,0x0b,0x12,0x14,0x36,0x85,0x09,0x82,0x85,0x08,0x83,
	0xe0,0xa3,0xff,0x12,0x14,0x36,0xdb,0xf8,0xc2,0xb0,0xd2,0xb1,0x12,0x13,0x8d,0x12,
	0x14,0x5b,0x22,0x30,0x37,0x2f,0x31,0x39,0x2f,0x31,0x33,0x00,0x31,0x38,0x3a,0x30,
	0x38,0x3a,0x34,0x36,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,
	0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1b,
	0x1c,0x1d,0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0xd3,
	0x10,0xaf,0x01,0xc3,0xc0,0xd0,0x8e,0x1d,0x8f,0x1e,0x12,0x13,0x6e,0xef,0x60,0xfa,
	0x85,0x1e,0x82,0x85,0x1d,0x83,0xe0,0x70,0x03,0xd3,0x80,0x01,0xc3,0x92,0x0a,0x30,
	0x0a,0x09,0x85,0x1e,0x82,0x85,0x1d,0x83,0x74,0x01,0xf0,0x12,0x14,0x6d,0xa2,0x0a,
	0xe4,0x33,0xff,0xd0,0xd0,0x92,0xaf,0x22,0xfd,0xe0,0xfe,0xa3,0xe0,0xff,0xd3,0xef,
	0x9d,0xec,0x64,0x80,0xf8,0xee,0x64,0x80,0x98,0x40,0x08,0xef,0x9d,0xfb,0xee,0x9c,
	0xfa,0x80,0x07,0xc3,0xed,0x9f,0xfb,0xec,0x9e,0xfa,0xd3,0xef,0x94,0x00,0xee,0x64,
	0x80,0x94,0x80,0x40,0x04,0xca,0x44,0x80,0xca,0xcf,0xeb,0xcf,0xce,0xea,0xce,0x22,
	0xce,0xed,0xce,0xef,0x14,0x60,0x09,0x04,0x70,0x26,0x90,0x40,0x33,0xe4,0xf0,0x22,
	0x90,0x42,0x53,0xe0,0x54,0xdf,0xf0,0x90,0x42,0x6c,0xe4,0xf0,0x90,0x42,0x69,0xf0,
	0xa3,0x12,0x14,0x29,0xcf,0xee,0xcf,0x12,0x12,0x51,0x90,0x40,0x33,0x74,0x01,0xf0,
	0x22,0xcd,0xef,0xcd,0xed,0x54,0x03,0x75,0xf0,0x10,0xa4,0xff,0x90,0x42,0x80,0xe0,
	0xfa,0xa3,0xe0,0x54,0xcf,0xfb,0xea,0x45,0xf0,0xfe,0xeb,0x4f,0xff,0x90,0x42,0x80,
	0xee,0xf0,0xa3,0xef,0xf0,0xed,0x13,0x13,0x54,0x3f,0x90,0x42,0x6b,0xf0,0x22,0x8e,
	0x08,0x8f,0x09,0xd2,0xb5,0xc2,0xb2,0x12,0x14,0x4f,0xc2,0xb1,0x7f,0x20,0x12,0x14,
	0x36,0xe4,0xff,0x12,0x14,0x36,0xaf,0x08,0x12,0x14,0x36,0xaf,0x09,0x12,0x14,0x36,
	0xc2,0xb0,0xd2,0xb1,0x12,0x13,0x8d,0x12,0x14,0x5b,0x22,0x90,0x30,0x1f,0xe0,0x54,
	0xfe,0xf0,0x90,0x37,0x33,0xe0,0x54,0xfb,0xf0,0x90,0x30,0x39,0xe4,0xf0,0x90,0x30,
	0x05,0xe0,0x54,0xfe,0xf0,0xe0,0x54,0xfb,0xf0,0x90,0x42,0x5f,0x74,0x03,0xf0,0x90,
	0x42,0x81,0xe0,0x54,0xfe,0xf0,0x22,0xe4,0xff,0xa2,0x0b,0xe4,0x33,0xfe,0xef,0xc3,
	0x13,0x24,0x2c,0x12,0x06,0x5a,0xee,0xf0,0x0f,0xbf,0x1e,0xed,0xe4,0xff,0xa2,0x0b,
	0xe4,0x33,0xfe,0xef,0x90,0x11,0x85,0x93,0x12,0x06,0x58,0xee,0xf0,0x0f,0xbf,0x2a,
	0xed,0x22,0x90,0x60,0x15,0xe0,0xc3,0x94,0x40,0x50,0xf7,0x90,0xbf,0xfd,0xe0,0x24,
	0xc0,0xf5,0x82,0xe4,0x34,0xbd,0xf5,0x83,0xef,0xf0,0x90,0xbf,0xfd,0xe0,0x04,0xf0,
	0xe0,0x54,0x3f,0xf0,0x90,0x60,0x1b,0x74,0x01,0xf0,0x22,0xcd,0xef,0xcd,0xcc,0xee,
	0xcc,0xd3,0xed,0x94,0xfa,0xec,0x94,0x00,0x40,0x0f,0x7f,0xfa,0x12,0x13,0xd9,0x74,
	0x06,0x2d,0xfd,0x74,0xff,0x3c,0xfc,0x80,0xe8,0xcf,0xed,0xcf,0x02,0x13,0xd9,0xd3,
	0x10,0xaf,0x01,0xc3,0x90,0x40,0xa4,0xe0,0xf5,0x33,0x85,0xdd,0x34,0x85,0xde,0x35,
	0x85,0xdf,0x36,0x92,0xaf,0xaf,0x36,0xae,0x35,0xad,0x34,0xac,0x33,0x22,0xd3,0x10,
	0xaf,0x01,0xc3,0xc0,0xd0,0x90,0x40,0xdf,0x74,0x0d,0xf0,0x90,0x40,0xfd,0xe0,0xb4,
	0x0d,0x04,0x7f,0x01,0x80,0x02,0x7f,0x00,0xd0,0xd0,0x92,0xaf,0x22,0xc2,0xb1,0x7f,
	0x05,0x12,0x14,0x36,0x7f,0x07,0xd2,0xb0,0xc2,0xb0,0xdf,0xfa,0xd2,0xb0,0xa2,0xb4,
	0x92,0x0b,0xc2,0xb0,0x20,0x0b,0xe6,0x22,0xd2,0xb5,0xc2,0xb2,0x12,0x14,0x4f,0xc2,
	0xb1,0x7f,0x60,0x12,0x14,0x36,0xc2,0xb0,0xd2,0xb1,0x12,0x13,0x8d,0x12,0x14,0x5b,
	0x22,0xc2,0xb1,0x7f,0x05,0x12,0x14,0x36,0x7f,0x08,0xd2,0xb0,0xa2,0xb4,0x33,0xc2,
	0xb0,0xdf,0xf7,0xc2,0xb0,0xd2,0xb1,0xff,0x22,0x90,0x40,0xa7,0xe0,0xfe,0x90,0x40,
	0xa7,0xe0,0xc3,0x9e,0xc3,0x9f,0x40,0x03,0xd3,0x80,0x01,0xc3,0x50,0xf0,0x22,0x02,
	0x2d,0xbb,0x80,0x01,0x20,0x00,0x4a,0x80,0x00,0x42,0x30,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xd3,0x10,0xaf,0x01,0xc3,0x90,0x40,0xa6,0xe0,0xf5,0x37,0x85,
	0xdf,0x38,0x92,0xaf,0xae,0x37,0xaf,0x38,0x22,0x78,0x00,0xe2,0xff,0x08,0xe2,0xfd,
	0x12,0x10,0x17,0xe4,0xf5,0x22,0xf5,0x2f,0x22,0xf0,0x90,0x42,0x53,0xe0,0x54,0xfe,
	0xf0,0xe0,0x54,0xfd,0xf0,0x22,0xef,0x7f,0x08,0x33,0x92,0xb6,0xd2,0xb0,0xc2,0xb0,
	0xdf,0xf7,0x22,0x90,0x40,0x4b,0x74,0x03,0xf0,0x90,0x40,0x4a,0xe4,0xf0,0x22,0xc2,
	0xb1,0x7f,0x06,0x12,0x14,0x36,0xc2,0xb0,0xd2,0xb1,0x22,0xc2,0xb1,0x7f,0x04,0x12,
	0x14,0x36,0xc2,0xb0,0xd2,0xb1,0x22,0x90,0x40,0xe3,0xef,0xf0,0x22,0x90,0x40,0xdf,
	0xe4,0xf0,0x22,0xf0,0xa3,0x22,
};

#define MIN_DRIVER_NUM            14
#define MAX_DRIVER_NUM            42
#define MIN_SENSOR_NUM            28
#define MAX_SENSOR_NUM            30

unsigned short gt900_short_threshold = 10;
unsigned short gt900_resistor_threshold = 800;
unsigned short gt900_resistor_warn_threshold = 500;
unsigned short gt900_gnd_resistor_threshold = 500;

//QFN88 package TX Pin, used for get channel number from Chip to Pad
const u8 ChannelPackage_TX[MAX_DRIVER_NUM] =  {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,
    20,21,22,23,24,25,/*26,*/27,28,29,30,31,32,33,34,35,36,37,
    38,39,40,41,42
};

#define GT9_DRV_HEAD    0x80
#define GT9_SEN_HEAD    0x00


// register defines for burning of dsp_short
#define _bRW_MISCTL__SRAM_BANK          0x4048
#define _bRW_MISCTL__MEM_CD_EN          0x4049
#define _bRW_MISCTL__CACHE_EN           0x404b
#define _bRW_MISCTL__TMR0_EN            0x40b0
#define _rRW_MISCTL__SWRST_B0_          0x4180
#define _bWO_MISCTL__CPU_SWRST_PULSE    0x4184
#define _rRW_MISCTL__BOOTCTL_B0_        0x4190
#define _rRW_MISCTL__BOOT_OPT_B0_       0x4218
#define _bRW_MISCTL__RG_OSC_CALIB       0x4268
#define _rRW_MISCTL__BOOT_CTL_          0x5094
#define _rRW_MISCTL__SHORT_BOOT_FLAG    0x5095


#define GTP_REG_DSP_SHORT               0xc000

#define GT9_REG_SEN_DRV_CNT             0x8062
#define GT9_REG_CFG_BEG                 0x8047
#define GT9_REG_KEY_VAL                 0x8093

#define GT9_REG_SEN_ORD     0x80B7
#define GT9_REG_DRV_ORD     0x80D5


struct gt9xx_short_info
{
    u8 master;
    u8 master_is_driver;
    u8 slave;
    u8 slave_is_driver;
    u16 short_code;
    u16 self_data;
    u16 impedance;
};

#define MYBIG_ENDIAN                1
#define MYLITLE_ENDIAN              0

#define	_BEYOND_MAX_LIMIT           0x0001
#define _BEYOND_MIN_LIMIT           0x0002
#define _BEYOND_KEY_MAX_LMT         0x0004
#define _BEYOND_KEY_MIN_LMT         0x0008
#define _BEYOND_UNIFORMITY_LMT      0x0010

#define	_MAX_TEST                   0x0001
#define _MIN_TEST                   0x0002
#define _KEY_MAX_TEST               0x0004
#define _KEY_MIN_TEST               0x0008
#define _UNIFORMITY_TEST            0x0010
#define _ACCORD_TEST                0x0020

#define _CHANNEL_PASS               0x0000

#define GTP_WAIT_RAW_MAX_TIMES      200
#define GTP_REG_RAW_DATA            0x9b60
//GT9XX RAW_DATA MAPPING
/*|------FLASH-----RAM--------|
  |------917D------0x9b60-----|
  |------615-------0x8b98-----|
  |------9293------0x8b98-----|
  |------915L------0x8b98-----|
  |------9110------0x8b98-----|
  |------9110P-----0x8b98-----|
  |------9271------0x8b98-----|*/
#define GTP_REG_READ_RAW            0x8040
#define GTP_REG_RAW_READY           0x814E
#define GTP_REG_RAW_DATA_GT9F       0x87C0

struct gt9xx_open_info
{
    u8 driver;
    u8 sensor;
    u16 raw_val;
    s32 beyond_type;	// limit type
    u8 times; 	// test fail times
    u8 key;		// 0: nonekey, others: key_no(1-4)
};


#endif

