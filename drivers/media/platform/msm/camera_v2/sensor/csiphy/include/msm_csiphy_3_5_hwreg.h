/* Copyright (c) 2015, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef MSM_CSIPHY_3_5_HWREG_H
#define MSM_CSIPHY_3_5_HWREG_H

#define ULPM_WAKE_UP_TIMER_MODE                   2
#define GLITCH_ELIMINATION_NUM                    0x12 /* bit [6:4] */

#include <sensor/csiphy/msm_csiphy.h>

struct csiphy_reg_parms_t csiphy_v3_5 = {
	.mipi_csiphy_interrupt_status0_addr = 0x8B0,
	.mipi_csiphy_interrupt_clear0_addr = 0x858,
	.mipi_csiphy_glbl_irq_cmd_addr = 0x828,
};

struct csiphy_reg_3ph_parms_t csiphy_v3_5_3ph = {
	/*MIPI CSI PHY registers*/
	{0x814, 0x0},
	{0x818, 0x1},
	{0x188, 0x7F},
	{0x18C, 0x7F},
	{0x190, 0x0},
	{0x104, 0x6},
	{0x108, 0x0},
	{0x10c, 0x0},
	{0x114, 0x20},
	{0x118, 0x3E},
	{0x11c, 0x41},
	{0x120, 0x41},
	{0x124, 0x7F},
	{0x128, 0x0},
	{0x12c, 0x0},
	{0x130, 0x1},
	{0x134, 0x0},
	{0x138, 0x0},
	{0x13C, 0x10},
	{0x140, 0x1},
	{0x144, GLITCH_ELIMINATION_NUM},
	{0x148, 0xFE},
	{0x14C, 0x1},
	{0x154, 0x0},
	{0x15C, 0x33},
	{0x160, ULPM_WAKE_UP_TIMER_MODE},
	{0x164, 0x48},
	{0x168, 0xA0},
	{0x16C, 0x17},
	{0x170, 0x41},
	{0x174, 0x41},
	{0x178, 0x3E},
	{0x17C, 0x0},
	{0x180, 0x0},
	{0x184, 0x7F},
	{0x1cc, 0x10},
	{0x81c, 0x6},
	{0x82c, 0xFF},
	{0x830, 0xFF},
	{0x834, 0xFB},
	{0x838, 0xFF},
	{0x83c, 0x7F},
	{0x840, 0xFF},
	{0x844, 0xFF},
	{0x848, 0xEF},
	{0x84c, 0xFF},
	{0x850, 0xFF},
	{0x854, 0xFF},
	{0x28, 0x0},
	{0x800, 0x0},
	{0x0, 0xD7},
	{0x4, 0x8},
	{0x8, 0x0},
	{0xC, 0xA5},
	{0x10, 0x52},
	{0x2C, 0x1},
	{0x30, 0x2},
	{0x34, 0x3},
	{0x38, 0x1},
	{0x3C, 0xB8},
	{0x1C, 0xA},
	{0x14, 0x0},
	{0x0, 0x0},
	{0x700, 0xC0},
};
#endif
