/*
 * (C) Copyright 2005 2N TELEKOMUNIKACE, Ladislav Michl
 *
 * Configuation settings for the TI OMAP NetStar board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
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

#include <configs/omap1510.h>

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM925T	1		/* This is an arm925t CPU */
#define CONFIG_OMAP	1		/* in a TI OMAP core */
#define CONFIG_OMAP1510 1		/* which is in a 5910 */

/* Input clock of PLL */
#define CONFIG_SYS_CLK_FREQ	150000000	/* 150MHz input clock */
#define CONFIG_XTAL_FREQ	12000000

#undef CONFIG_USE_IRQ			/* we don't need IRQ/FIQ stuff */

#define CONFIG_MISC_INIT_R		/* There is nothing to really init */
#define BOARD_LATE_INIT			/* but we flash the LEDs here */

#define CONFIG_CMDLINE_TAG		1	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS	1
#define CONFIG_INITRD_TAG		1

#define CONFIG_SILENT_CONSOLE		1	/* enable silent startup */
#define CONFIG_SYS_CONSOLE_INFO_QUIET

/*
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS	1		/* we have 1 bank of DRAM */
#define PHYS_SDRAM_1		0x10000000	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE	(64 * 1024 * 1024)
#define PHYS_FLASH_1		0x00000000	/* Flash Bank #1 */

/*
 * FLASH organization
 */
#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1
#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define PHYS_FLASH_1_SIZE		(1 * 1024 * 1024)
#define CONFIG_SYS_MAX_FLASH_SECT	19
#define CONFIG_SYS_FLASH_ERASE_TOUT	(5*CONFIG_SYS_HZ) /* in ticks */
#define CONFIG_SYS_FLASH_WRITE_TOUT	(5*CONFIG_SYS_HZ)

#define CONFIG_SYS_MONITOR_BASE		PHYS_FLASH_1
#define CONFIG_SYS_MONITOR_LEN		(256 * 1024)

/*
 * Environment settings
 */
#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_ADDR		0x4000
#define CONFIG_ENV_SIZE		(8 * 1024)
#define CONFIG_ENV_SECT_SIZE	(8 * 1024)
#define CONFIG_ENV_ADDR_REDUND	0x6000
#define CONFIG_ENV_SIZE_REDUND	CONFIG_ENV_SIZE
#define CONFIG_ENV_OVERWRITE

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* size in bytes reserved for initial data */
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)

/*
 * The stack size is set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	(1 * 1024 * 1024)	/* regular stack */

/*
 * Hardware drivers
 */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		(CONFIG_XTAL_FREQ)	/* can be 12M/32Khz or 48Mhz  */
#define CONFIG_SYS_NS16550_COM1		OMAP1510_UART1_BASE	/* uart1 */

#define CONFIG_DRIVER_SMC91111
#define CONFIG_SMC91111_BASE		0x04000300

#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x04000000 + (2 << 23)
#define NAND_ALLOW_ERASE_ALL		1


#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*#define CONFIG_SKIP_RELOCATE_UBOOT*/
/*#define CONFIG_SKIP_LOWLEVEL_INIT */

/*
 * partitions (mtdparts command line support)
 */
#define CONFIG_JFFS2_CMDLINE
#define MTDIDS_DEFAULT		"nor0=omapflash.0,nand0=omapnand.0"
#define MTDPARTS_DEFAULT	"mtdparts=" \
	"omapflash.0:8k@16k(env),8k(r_env),448k@576k(u-boot);" \
	"omapnand.0:4M(kernel0),40M(rootfs0),4M(kernel1),40M(rootfs1),-(data)"


/*
 * Command line configuration.
 */
#define CONFIG_CMD_BDI
#define CONFIG_CMD_BOOTD
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_FLASH
#define CONFIG_CMD_IMI
#define CONFIG_CMD_JFFS2
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_NAND
#define CONFIG_CMD_NET
#define CONFIG_CMD_PING
#define CONFIG_CMD_RUN


#define CONFIG_JFFS2_NAND	1	/* jffs2 on nand support */

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_BOOTPATH

#define CONFIG_LOOPW

#define CONFIG_BOOTDELAY	3
#define CONFIG_ZERO_BOOTDELAY_CHECK	/* allow to break in always */
#undef  CONFIG_BOOTARGS		/* the boot command will set bootargs*/
#define CONFIG_SYS_AUTOLOAD		"n"		/* No autoload */
#define CONFIG_BOOTCOMMAND	"run fboot"
#define CONFIG_PREBOOT		"run setup"
#define	CONFIG_EXTRA_ENV_SETTINGS						\
	"autostart=yes\0"							\
	"ospart=0\0"								\
	"setup=setenv bootargs console=ttyS0,$baudrate "			\
		"$mtdparts\0"							\
	"setpart="								\
	"if test -n $swapos; then "						\
		"setenv swapos; saveenv; "					\
	"else "									\
		"if test $ospart -eq 0; then setenv ospart 1;"			\
			"else setenv ospart 0;		fi; "			\
	"fi\0"									\
	"nfsargs=setenv bootargs $bootargs "					\
		"ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname::off "	\
		"nfsroot=$rootpath root=/dev/nfs\0"				\
	"flashargs=run setpart;setenv bootargs $bootargs "			\
		"root=mtd:rootfs$ospart ro "					\
		"rootfstype=jffs2\0"						\
	"ip=$ipaddr:$serverip:$gatewayip:$netmask:$hostname::off\0"		\
	"fboot=run flashargs;nboot kernel$ospart\0"				\
	"nboot=bootp;run nfsargs;tftp\0"

#if 0	/* feel free to disable for development */
#define	CONFIG_AUTOBOOT_KEYED		/* Enable password protection	*/
#define CONFIG_AUTOBOOT_PROMPT		\
	"\nNetStar PBX - boot in %d secs...\n", bootdelay
#define CONFIG_AUTOBOOT_DELAY_STR	"."	/* 1st "password"	*/
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP				/* undef to save memory		*/
#define CONFIG_SYS_PROMPT		"# "		/* Monitor Command Prompt	*/
#define CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size	*/
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16) /* Print Buffer Size */
#define CONFIG_SYS_MAXARGS		16		/* max number of command args	*/
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size	*/

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_AUTO_COMPLETE

#define CONFIG_SYS_MEMTEST_START	PHYS_SDRAM_1
#define CONFIG_SYS_MEMTEST_END		PHYS_SDRAM_1 + PHYS_SDRAM_1_SIZE - \
				(CONFIG_SYS_MONITOR_LEN + CONFIG_SYS_MALLOC_LEN + CONFIG_STACKSIZE)

#undef	CONFIG_SYS_CLKS_IN_HZ		/* everything, incl board info, in Hz */

#define CONFIG_SYS_LOAD_ADDR		PHYS_SDRAM_1 + 0x400000	/* default load address */

/* The 1510 has 3 timers, they can be driven by the RefClk (12Mhz) or by DPLL1.
 * This time is further subdivided by a local divisor.
 */
#define CONFIG_SYS_TIMERBASE		OMAP1510_TIMER1_BASE
#define CONFIG_SYS_PVT			7		/* 2^(pvt+1), divide by 256 */
#define CONFIG_SYS_HZ			((CONFIG_SYS_CLK_FREQ)/(2 << CONFIG_SYS_PVT))

#define OMAP5910_DPLL_DIV	1
#define OMAP5910_DPLL_MUL	((CONFIG_SYS_CLK_FREQ * \
				 (1 << OMAP5910_DPLL_DIV)) / CONFIG_XTAL_FREQ)

#define OMAP5910_ARM_PER_DIV	2	/* CKL/4 */
#define OMAP5910_LCD_DIV	2	/* CKL/4 */
#define OMAP5910_ARM_DIV	0	/* CKL/1 */
#define OMAP5910_DSP_DIV	0	/* CKL/1 */
#define OMAP5910_TC_DIV		1	/* CKL/2 */
#define OMAP5910_DSP_MMU_DIV	1	/* CKL/2 */
#define OMAP5910_ARM_TIM_SEL	1	/* CKL used for MPU timers */

#define OMAP5910_ARM_EN_CLK	0x03d6	/* 0000 0011 1101 0110b  Clock Enable */
#define OMAP5910_ARM_CKCTL	((OMAP5910_ARM_PER_DIV)  |	\
				 (OMAP5910_LCD_DIV << 2) |	\
				 (OMAP5910_ARM_DIV << 4) |	\
				 (OMAP5910_DSP_DIV << 6) |	\
				 (OMAP5910_TC_DIV << 8) |	\
				 (OMAP5910_DSP_MMU_DIV << 10) |	\
				 (OMAP5910_ARM_TIM_SEL << 12))

#endif	/* __CONFIG_H */
