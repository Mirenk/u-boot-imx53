/*
 * Copyright (C) 2010-2011 Freescale Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <config.h>
#include <asm/arch/mx53.h>

#ifdef	CONFIG_FLASH_HEADER
#ifndef CONFIG_FLASH_HEADER_OFFSET
# error "Must define the offset of flash header"
#endif

#define CPU_2_BE_32(l) \
       ((((l) & 0x000000FF) << 24) | \
	(((l) & 0x0000FF00) << 8)  | \
	(((l) & 0x00FF0000) >> 8)  | \
	(((l) & 0xFF000000) >> 24))

#define MXC_DCD_ITEM(i, addr, val)   \
dcd_node_##i:                        \
        .word CPU_2_BE_32(addr) ;     \
        .word CPU_2_BE_32(val)  ;     \

.section ".text.flasheader", "x"
	b	_start
	.org	CONFIG_FLASH_HEADER_OFFSET
ivt_header:       .word 0x402000D1 /* Tag=0xD1, Len=0x0020, Ver=0x40 */
app_code_jump_v:  .word _start
reserv1:          .word 0x0
dcd_ptr:          .word dcd_hdr
boot_data_ptr:	  .word boot_data
self_ptr:         .word ivt_header
app_code_csf:     .word 0x0
reserv2:          .word 0x0

boot_data:        .word 0x77800000
image_len:        .word _end_of_copy - TEXT_BASE + CONFIG_FLASH_HEADER_OFFSET
plugin:           .word 0x0

dcd_hdr:          .word 0x40A001D2 /* Tag=0xD2, Len=51*8 + 4 + 4, Ver=0x40 */
write_dcd_cmd:    .word 0x049C01CC /* Tag=0xCC, Len=51*8 + 4, Param=4 */

/* DCD */
MXC_DCD_ITEM(1, IOMUXC_BASE_ADDR + 0x554, 0x00300000)
MXC_DCD_ITEM(2, IOMUXC_BASE_ADDR + 0x558, 0x00300040)
MXC_DCD_ITEM(3, IOMUXC_BASE_ADDR + 0x560, 0x00300000)
MXC_DCD_ITEM(4, IOMUXC_BASE_ADDR + 0x564, 0x00300040)
MXC_DCD_ITEM(5, IOMUXC_BASE_ADDR + 0x568, 0x00300040)
MXC_DCD_ITEM(6, IOMUXC_BASE_ADDR + 0x570, 0x00300000)
MXC_DCD_ITEM(7, IOMUXC_BASE_ADDR + 0x574, 0x00300000)
MXC_DCD_ITEM(8, IOMUXC_BASE_ADDR + 0x578, 0x00300000)
MXC_DCD_ITEM(9, IOMUXC_BASE_ADDR + 0x57c, 0x00300040)
MXC_DCD_ITEM(10, IOMUXC_BASE_ADDR + 0x580, 0x00300040)
MXC_DCD_ITEM(11, IOMUXC_BASE_ADDR + 0x584, 0x00300000)
MXC_DCD_ITEM(12, IOMUXC_BASE_ADDR + 0x588, 0x00300000)
MXC_DCD_ITEM(13, IOMUXC_BASE_ADDR + 0x590, 0x00300040)
MXC_DCD_ITEM(14, IOMUXC_BASE_ADDR + 0x594, 0x00300000)
MXC_DCD_ITEM(15, IOMUXC_BASE_ADDR + 0x6f0, 0x00300000)
MXC_DCD_ITEM(16, IOMUXC_BASE_ADDR + 0x6f4, 0x00000000)
MXC_DCD_ITEM(17, IOMUXC_BASE_ADDR + 0x6fc, 0x00000000)
MXC_DCD_ITEM(18, IOMUXC_BASE_ADDR + 0x714, 0x00000000)
MXC_DCD_ITEM(19, IOMUXC_BASE_ADDR + 0x718, 0x00300000)
MXC_DCD_ITEM(20, IOMUXC_BASE_ADDR + 0x71c, 0x00300000)
MXC_DCD_ITEM(21, IOMUXC_BASE_ADDR + 0x720, 0x00300000)
MXC_DCD_ITEM(22, IOMUXC_BASE_ADDR + 0x724, 0x04000000)
MXC_DCD_ITEM(23, IOMUXC_BASE_ADDR + 0x728, 0x00300000)
MXC_DCD_ITEM(24, IOMUXC_BASE_ADDR + 0x72c, 0x00300000)
MXC_DCD_ITEM(25, ESDCTL_BASE_ADDR + 0x088, 0x35343535)
MXC_DCD_ITEM(26, ESDCTL_BASE_ADDR + 0x090, 0x4d444c44)
MXC_DCD_ITEM(27, ESDCTL_BASE_ADDR + 0x07c, 0x01370138)
MXC_DCD_ITEM(28, ESDCTL_BASE_ADDR + 0x080, 0x013b013c)
MXC_DCD_ITEM(29, ESDCTL_BASE_ADDR + 0x018, 0x00011740)
MXC_DCD_ITEM(30, ESDCTL_BASE_ADDR + 0x000, 0xc3190000)
MXC_DCD_ITEM(31, ESDCTL_BASE_ADDR + 0x00c, 0x9f5152e3)
MXC_DCD_ITEM(32, ESDCTL_BASE_ADDR + 0x010, 0xb68e8a63)
MXC_DCD_ITEM(33, ESDCTL_BASE_ADDR + 0x014, 0x01ff00db)
MXC_DCD_ITEM(34, ESDCTL_BASE_ADDR + 0x02c, 0x000026d2)
MXC_DCD_ITEM(35, ESDCTL_BASE_ADDR + 0x030, 0x009f0e21)
MXC_DCD_ITEM(36, ESDCTL_BASE_ADDR + 0x008, 0x12273030)
MXC_DCD_ITEM(37, ESDCTL_BASE_ADDR + 0x004, 0x0002002d)
MXC_DCD_ITEM(38, ESDCTL_BASE_ADDR + 0x01c, 0x00008032)
MXC_DCD_ITEM(39, ESDCTL_BASE_ADDR + 0x01c, 0x00008033)
MXC_DCD_ITEM(40, ESDCTL_BASE_ADDR + 0x01c, 0x00028031)
MXC_DCD_ITEM(41, ESDCTL_BASE_ADDR + 0x01c, 0x052080b0)
MXC_DCD_ITEM(42, ESDCTL_BASE_ADDR + 0x01c, 0x04008040)
MXC_DCD_ITEM(43, ESDCTL_BASE_ADDR + 0x01c, 0x0000803a)
MXC_DCD_ITEM(44, ESDCTL_BASE_ADDR + 0x01c, 0x0000803b)
MXC_DCD_ITEM(45, ESDCTL_BASE_ADDR + 0x01c, 0x00028039)
MXC_DCD_ITEM(46, ESDCTL_BASE_ADDR + 0x01c, 0x05208138)
MXC_DCD_ITEM(47, ESDCTL_BASE_ADDR + 0x01c, 0x04008048)
MXC_DCD_ITEM(48, ESDCTL_BASE_ADDR + 0x020, 0x00005800)
MXC_DCD_ITEM(49, ESDCTL_BASE_ADDR + 0x040, 0x04b80003)
MXC_DCD_ITEM(50, ESDCTL_BASE_ADDR + 0x058, 0x00022227)
MXC_DCD_ITEM(51, ESDCTL_BASE_ADDR + 0x01C, 0x00000000)

#endif
