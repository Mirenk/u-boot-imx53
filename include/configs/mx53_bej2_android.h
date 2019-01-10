/*
 * Copyright (C) 2011 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the MX53-SMD Freescale board.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/arch/mx53.h>

 /* High Level Configuration Options */
#define CONFIG_ARMV7		/* This is armv7 Cortex-A8 CPU core */
#define CONFIG_MXC
#define CONFIG_MX53
#define CONFIG_MX53_BEJ2
#define CONFIG_FLASH_HEADER
#define CONFIG_FLASH_HEADER_OFFSET 0x400
#define CONFIG_MX53_CLK32	32768

#define CONFIG_SKIP_RELOCATE_UBOOT

#define CONFIG_ARCH_CPU_INIT
#define CONFIG_ARCH_MMU

#define CONFIG_MX53_HCLK_FREQ	24000000
#define CONFIG_SYS_PLL2_FREQ	392
#define CONFIG_SYS_AHB_PODF	2
#define CONFIG_SYS_AXIA_PODF	0
#define CONFIG_SYS_AXIB_PODF	1

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_SYS_64BIT_VSPRINTF

#define BOARD_LATE_INIT
/*
 * Disabled for now due to build problems under Debian and a significant
 * increase in the final file size: 144260 vs. 109536 Bytes.
 */

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_REVISION_TAG		1
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_INITRD_TAG		1

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 2 * 1024 * 1024)
/* size in bytes reserved for initial data */
#define CONFIG_SYS_GBL_DATA_SIZE	128

/*
 * Hardware drivers
 */
#define CONFIG_MXC_UART 1
#define CONFIG_UART_BASE_ADDR	UART1_BASE_ADDR

/*
 * Android support Configs
 */

/* Android fastboot configs */
#define CONFIG_USB_DEVICE
#define CONFIG_IMX_UDC		       1
#define CONFIG_FASTBOOT		       1
#define CONFIG_FASTBOOT_STORAGE_EMMC_SATA
#define CONFIG_FASTBOOT_VENDOR_ID      0xbb4
#define CONFIG_FASTBOOT_PRODUCT_ID     0xc01
#define CONFIG_FASTBOOT_BCD_DEVICE     0x311
#define CONFIG_FASTBOOT_MANUFACTURER_STR  "Freescale"
#define CONFIG_FASTBOOT_PRODUCT_NAME_STR "i.mx53 smd"
#define CONFIG_FASTBOOT_CONFIGURATION_STR  "Android fastboot"
#define CONFIG_FASTBOOT_INTERFACE_STR	 "Android fastboot"
#define CONFIG_FASTBOOT_SERIAL_NUM	"12345"
#define CONFIG_FASTBOOT_SATA_NO		 0
#define CONFIG_FASTBOOT_TRANSFER_BUF	0x80000000
#define CONFIG_FASTBOOT_TRANSFER_BUF_SIZE 0x9400000 /* 148M byte */

#define CONFIG_ANDROID_RECOVERY

//#define CONFIG_MTD_DEVICE
//#define CONFIG_MTD_PARTITIONS


#define CONFIG_ANDROID_RECOVERY_BOOTARGS_MMC \
	"setenv bootargs ${bootargs} root=/dev/mmcblk0p4 rootfs=ext4"
//	"setenv bootargs ${bootargs} init=/init root=/dev/mmcblk0p4 rootfs=ext4 video=mxcdi1fb:RGB24,WSVGA ldb=di1 di1_primary"

#define CONFIG_ANDROID_RECOVERY_BOOTCMD_MMC  \
	"run bootargs_android_recovery;"	\
	"mmc read 1 ${loadaddr} 0x1000 0x2000;bootm"
#define CONFIG_ANDROID_RECOVERY_CMD_FILE "/recovery/command"

#define CONFIG_ANDROID_SYSTEM_PARTITION_MMC 2
#define CONFIG_ANDROID_RECOVERY_PARTITION_MMC 4
#define CONFIG_ANDROID_CACHE_PARTITION_MMC 6

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}


/***********************************************************
 * Command definition
 ***********************************************************/

#include <config_cmd_default.h>

//#define CONFIG_CMD_DATE

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_NET_RETRY_COUNT	100
#define CONFIG_NET_MULTI 1
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_DNS

#define CONFIG_CMD_MMC
#define CONFIG_CMD_SPI
#define CONFIG_CMD_I2C
#define CONFIG_CMD_SF
#define CONFIG_CMD_ENV

#define CONFIG_CMD_IIM

#define CONFIG_CMD_CLOCK
#define CONFIG_REF_CLK_FREQ CONFIG_MX53_HCLK_FREQ

//#define CONFIG_CMD_SATA
#undef CONFIG_CMD_IMLS

/* download mode command */
//#define CONFIG_CMD_IMX_DOWNLOAD_MODE

#define CONFIG_BOOTDELAY	1

#define CONFIG_PRIME	"FEC0"

#define CONFIG_LOADADDR		0x70800000	/* loadaddr env var */
#define CONFIG_RD_LOADADDR	(CONFIG_LOADADDR + 0x600000)

#if 1 /*R10.3.2 or R10.4*/
#define	CONFIG_EXTRA_ENV_SETTINGS					\
		"netdev=eth0\0"						\
		"ethprime=FEC0\0"					\
		"ethaddr=00:04:9f:00:ea:d3\0"		\
		"bootfile=uImage\0"	\
		"loadaddr=0x70800000\0"				\
		"rd_loadaddr=0x70E00000\0"		\
		"lvds_num=1\0"						\
		"splashimage=0xcfd00000\0"			\
		"splashpos=396,200\0"				\
		"bootargs=init=/init " \
			"androidboot.console=ttymxc0 video=mxcdi1fb:RGB24,WSVGA " \
			"ldb=di1 di1_primary pmem=32M,64M fbmem=8M gpu_memory=64M\0" \
		"bootcmd_SD=mmc read 1 ${loadaddr} 0x1000 0x2000;" \
			"mmc read 1 ${rd_loadaddr} 0x3000 0x300\0" \
		"bootcmd=run bootcmd_SD; bootm ${loadaddr} ${rd_loadaddr}\0" \
		"sdramtest_full=watchdog start;" \
			"sdramtest 0x70008000 0x073f8000;" \
			"sdramtest 0x77900000 0x18700000;" \
			"sdramtest 0xb0000000 0x20000000;" \
			"setenv autorun /system/bin/display_sdramtest_success"
#else /*R10.3.1*/
#define	CONFIG_EXTRA_ENV_SETTINGS					\
		"netdev=eth0\0"						\
		"ethprime=FEC0\0"					\
		"ethaddr=00:04:9f:00:ea:d3\0"		\
		"bootfile=uImage\0"	\
		"loadaddr=0x70800000\0"				\
		"rd_loadaddr=0x70E00000\0"		\
		"lvds_num=1\0"						\
		"splashimage=0xcfd00000\0"			\
		"splashpos=396,200\0"				\
		"bootargs=init=/init " \
			"androidboot.console=ttymxc0 video=mxcdi1fb:RGB24,WSVGA " \
			"ldb=di1 di1_primary gpu_nommu gpu_memory=64M\0" \
		"bootcmd_SD=mmc read 1 ${loadaddr} 0x800 0x2000;" \
			"mmc read 1 ${rd_loadaddr} 0x3000 0x300\0" \
		"bootcmd=run bootcmd_SD; bootm ${loadaddr} ${rd_loadaddr}\0" \
		"sdramtest_full=watchdog start;" \
			"sdramtest 0x70008000 0x073f8000;" \
			"sdramtest 0x77900000 0x18700000;" \
			"sdramtest 0xb0000000 0x20000000;" \
			"setenv autorun /system/bin/display_sdramtest_success"
#endif

#define CONFIG_ARP_TIMEOUT	200UL

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_PROMPT		"MX53-BEJ2 U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE /* Boot Argument Buffer Size */

#define CONFIG_SYS_MEMTEST_START	0	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x10000

#undef	CONFIG_SYS_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR

#define CONFIG_SYS_HZ				1000

#define CONFIG_CMDLINE_EDITING	1

#define CONFIG_FEC0_IOBASE	FEC_BASE_ADDR
#define CONFIG_FEC0_PINMUX	-1
#define CONFIG_FEC0_PHY_ADDR	-1
#define CONFIG_FEC0_MIIBASE	-1

#define CONFIG_GET_FEC_MAC_ADDR_FROM_IIM
#define CONFIG_IIM_MAC_ADDR_OFFSET      0x24

#define CONFIG_MXC_FEC
#define CONFIG_MII
#define CONFIG_MII_GASKET
#define CONFIG_DISCOVER_PHY


/*
 * RTC Configs
 */
#define CONFIG_RTC_MXC
#define CONFIG_RTC_DA9052

/*
 * FUSE Configs
 * */
#ifdef CONFIG_CMD_IIM
	#define CONFIG_IMX_IIM
	#define IMX_IIM_BASE    IIM_BASE_ADDR
	#define CONFIG_IIM_MAC_BANK     1
	#define CONFIG_IIM_MAC_ROW      9
#endif

/*
 * I2C Configs
 */
#ifdef CONFIG_CMD_I2C
	#define CONFIG_HARD_I2C         1
	#define CONFIG_I2C_MXC          1
	#define CONFIG_SYS_I2C_PORT             I2C1_BASE_ADDR
	#define CONFIG_SYS_I2C_SPEED            100000
	#define CONFIG_SYS_I2C_SLAVE            0xfe
#endif


/*
 * SPI Configs
 */
#ifdef CONFIG_CMD_SF
	#define CONFIG_FSL_SF		1
	#define CONFIG_SPI_FLASH_IMX_M25PXX	1
	#define CONFIG_SPI_FLASH_CS	1
	#define CONFIG_IMX_ECSPI
	#define IMX_CSPI_VER_2_3	1
	#define MAX_SPI_BYTES		(64 * 4)
#endif

/*
 * MMC Configs
 */
#ifdef CONFIG_CMD_MMC
	#define CONFIG_MMC				1
	#define CONFIG_GENERIC_MMC
	#define CONFIG_IMX_MMC
	#define CONFIG_SYS_FSL_ESDHC_NUM        2
	#define CONFIG_SYS_FSL_ESDHC_ADDR       0
	#define CONFIG_SYS_MMC_ENV_DEV  0
	#define CONFIG_DOS_PARTITION	1
	#define CONFIG_CMD_FAT		1
	#define CONFIG_CMD_EXT2		1

	/* detect whether ESDHC1 or ESDHC3 is boot device */
	#define CONFIG_DYNAMIC_MMC_DEVNO

	#define CONFIG_BOOT_PARTITION_ACCESS
	#define CONFIG_EMMC_DDR_MODE
	#define CONFIG_EMMC_DDR_PORT_DETECT
	/* port 1 (ESDHC3) is 8 bit */
	#define CONFIG_MMC_8BIT_PORTS	0x2
#endif

/*
 * SATA Configs
 */
#ifdef CONFIG_CMD_SATA
  #define CONFIG_DWC_AHSATA
  #define CONFIG_SYS_SATA_MAX_DEVICE      1
  #define CONFIG_DWC_AHSATA_PORT_ID       0
  #define CONFIG_DWC_AHSATA_BASE_ADDR     SATA_BASE_ADDR
  #define CONFIG_LBA48
  #define CONFIG_LIBATA
#endif

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(128 * 1024)	/* regular stack */

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	2
#define PHYS_SDRAM_1		CSD0_BASE_ADDR
#define PHYS_SDRAM_1_SIZE	(512 * 1024 * 1024)
#define PHYS_SDRAM_2		CSD1_BASE_ADDR
#if 1
#define PHYS_SDRAM_2_SIZE	(512 * 1024 * 1024)
#define iomem_valid_addr(addr, size) \
       ((addr >= PHYS_SDRAM_1 && addr <= (PHYS_SDRAM_1 + PHYS_SDRAM_1_SIZE)) \
       || (addr >= PHYS_SDRAM_2 && addr <= (PHYS_SDRAM_2 + PHYS_SDRAM_2_SIZE)))
#else
#define PHYS_SDRAM_2_SIZE	0
#define iomem_valid_addr(addr, size) \
       ((addr >= PHYS_SDRAM_1 && addr <= (PHYS_SDRAM_1 + PHYS_SDRAM_1_SIZE)))
#endif

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH

/* Monitor at beginning of flash */
#define CONFIG_FSL_ENV_IN_MMC

#define CONFIG_ENV_SECT_SIZE    (128 * 1024)
#define CONFIG_ENV_SIZE         CONFIG_ENV_SECT_SIZE
#define CONFIG_SERIAL_SIZE      (512)

#if defined(CONFIG_FSL_ENV_IN_NAND)
	#define CONFIG_ENV_IS_IN_NAND 1
	#define CONFIG_ENV_OFFSET	0x100000
#elif defined(CONFIG_FSL_ENV_IN_MMC)
	#define CONFIG_ENV_IS_IN_MMC	1
	#define CONFIG_ENV_OFFSET	(768 * 1024)
	#define CONFIG_SERIAL_OFFSET	(1024 * 1024)
#elif defined(CONFIG_FSL_ENV_IN_SF)
	#define CONFIG_ENV_IS_IN_SPI_FLASH	1
	#define CONFIG_ENV_SPI_CS		1
	#define CONFIG_ENV_OFFSET       (768 * 1024)
#else
	#define CONFIG_ENV_IS_NOWHERE	1
#endif

#define CONFIG_SPLASH_SCREEN
#ifdef CONFIG_SPLASH_SCREEN
	/*
	 * Framebuffer and LCD
	 */
	#define CONFIG_LCD
	#define CONFIG_VIDEO_MX5
	#define CONFIG_IPU_CLKRATE	200000000
	#define CONFIG_SYS_CONSOLE_ENV_OVERWRITE
//	#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
	#define CONFIG_SYS_CONSOLE_IS_IN_ENV
	#define LCD_BPP		LCD_COLOR16
//	#define CONFIG_CMD_BMP
//	#define CONFIG_BMP_8BPP
	#define CONFIG_FB_BASE	(TEXT_BASE + 0x300000)
//	#define CONFIG_FB_BASE	0xCFB00000
//	#define CONFIG_SPLASH_SCREEN_ALIGN
	#define CONFIG_SYS_WHITE_ON_BLACK

	#define CONFIG_IMX_PWM
	#define IMX_PWM1_BASE    PWM1_BASE_ADDR
	#define IMX_PWM2_BASE    PWM2_BASE_ADDR
#endif

#define CONFIG_HW_WATCHDOG 0

#endif				/* __CONFIG_H */
