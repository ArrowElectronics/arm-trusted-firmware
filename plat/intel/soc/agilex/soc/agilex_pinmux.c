/*
 * Copyright (c) 2019-2022, Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <lib/mmio.h>

#include "agilex_pinmux.h"
#include "socfpga_system_manager.h"

const uint32_t sysmgr_pinmux_array_sel[] = {
	0x00000000, 0x00000001, /* usb */
	0x00000004, 0x00000001,
	0x00000008, 0x00000001,
	0x0000000c, 0x00000001,
	0x00000010, 0x00000001,
	0x00000014, 0x00000001,
	0x00000018, 0x00000001,
	0x0000001c, 0x00000001,
	0x00000020, 0x00000001,
	0x00000024, 0x00000001,
	0x00000028, 0x00000001,
	0x0000002c, 0x00000001,
	0x00000030, 0x00000000, /* emac0 */
	0x00000034, 0x00000000,
	0x00000038, 0x00000000,
	0x0000003c, 0x00000000,
	0x00000040, 0x00000000,
	0x00000044, 0x00000000,
	0x00000048, 0x00000000,
	0x0000004c, 0x00000000,
	0x00000050, 0x00000000,
	0x00000054, 0x00000000,
	0x00000058, 0x00000000,
	0x0000005c, 0x00000000,
	0x00000060, 0x00000008, /* gpio1 */
	0x00000064, 0x00000008,
	0x00000068, 0x00000005,  /* uart0 tx */
	0x0000006c, 0x00000005,  /*  uart 0 rx */
	0x00000070, 0x00000008,  /*  gpio */
	0x00000074, 0x00000008,
	0x00000078, 0x00000004, /* i2c1 */
	0x0000007c, 0x00000004,
	0x00000080, 0x00000007,  /* jtag */
	0x00000084, 0x00000007,
	0x00000088, 0x00000007,
	0x0000008c, 0x00000007,
	0x00000090, 0x00000001,  /* sdmmc data0 */
	0x00000094, 0x00000001,
	0x00000098, 0x00000001,
	0x0000009c, 0x00000001,
	0x00000100, 0x00000001,
	0x00000104, 0x00000001,  /* sdmmc.data3 */
	0x00000108, 0x00000008,  /* loan */
	0x0000010c, 0x00000008,   /* gpio */
	0x00000110, 0x00000008,
	0x00000114, 0x00000008,  /* gpio1.io21 */
	0x00000118, 0x00000005,  /* mdio0.mdio */
	0x0000011c, 0x00000005  /* mdio0.mdc */
};

const uint32_t sysmgr_pinmux_array_ctrl[] = {
	0x00000000, 0x00502c38, /* Q1_1 */
	0x00000004, 0x00102c38,
	0x00000008, 0x00502c38,
	0x0000000c, 0x00502c38,
	0x00000010, 0x00502c38,
	0x00000014, 0x00502c38,
	0x00000018, 0x00502c38,
	0x0000001c, 0x00502c38,
	0x00000020, 0x00502c38,
	0x00000024, 0x00502c38,
	0x00000028, 0x00502c38,
	0x0000002c, 0x00502c38,
	0x00000030, 0x00102c38, /* Q2_1 */
	0x00000034, 0x00102c38,
	0x00000038, 0x00502c38,
	0x0000003c, 0x00502c38,
	0x00000040, 0x00102c38,
	0x00000044, 0x00102c38,
	0x00000048, 0x00502c38,
	0x0000004c, 0x00502c38,
	0x00000050, 0x00102c38,
	0x00000054, 0x00102c38,
	0x00000058, 0x00502c38,
	0x0000005c, 0x00502c38,
	0x00000060, 0x00502c38, /* Q3_1 */
	0x00000064, 0x00502c38,
	0x00000068, 0x00102c38,
	0x0000006c, 0x00502c38,
	0x000000d0, 0x00502c38,
	0x000000d4, 0x00502c38,
	0x000000d8, 0x00542c38,
	0x000000dc, 0x00542c38,
	0x000000e0, 0x00502c38,
	0x000000e4, 0x00502c38,
	0x000000e8, 0x00102c38,
	0x000000ec, 0x00502c38,
	0x000000f0, 0x00502c38, /* Q4_1 */
	0x000000f4, 0x00502c38,
	0x000000f8, 0x00102c38,
	0x000000fc, 0x00502c38,
	0x00000100, 0x00502c38,
	0x00000104, 0x00502c38,
	0x00000108, 0x00102c38,
	0x0000010c, 0x00502c38,
	0x00000110, 0x00502c38,
	0x00000114, 0x00502c38,
	0x00000118, 0x00542c38,
	0x0000011c, 0x00102c38
};

const uint32_t sysmgr_pinmux_array_fpga[] = {
	0x00000000, 0x00000000,
	0x00000004, 0x00000000,
	0x00000008, 0x00000000,
	0x0000000c, 0x00000000,
	0x00000010, 0x00000000,
	0x00000014, 0x00000000,
	0x00000018, 0x00000000,
	0x0000001c, 0x00000000,
	0x00000020, 0x00000000,
	0x00000028, 0x00000000,
	0x0000002c, 0x00000000,
	0x00000030, 0x00000000,
	0x00000034, 0x00000000,
	0x00000038, 0x00000000,
	0x0000003c, 0x00000000,
	0x00000040, 0x00000000,
	0x00000044, 0x00000000,
	0x00000048, 0x00000000,
	0x00000050, 0x00000000,
	0x00000054, 0x00000000,
	0x00000058, 0x0000002a
};

const uint32_t sysmgr_pinmux_array_iodelay[] = {
	0x00000000, 0x00000000,
	0x00000004, 0x00000000,
	0x00000008, 0x00000000,
	0x0000000c, 0x00000000,
	0x00000010, 0x00000000,
	0x00000014, 0x00000000,
	0x00000018, 0x00000000,
	0x0000001c, 0x00000000,
	0x00000020, 0x00000000,
	0x00000024, 0x00000000,
	0x00000028, 0x00000000,
	0x0000002c, 0x00000000,
	0x00000030, 0x00000000,
	0x00000034, 0x00000000,
	0x00000038, 0x00000000,
	0x0000003c, 0x00000000,
	0x00000040, 0x00000000,
	0x00000044, 0x00000000,
	0x00000048, 0x00000000,
	0x0000004c, 0x00000000,
	0x00000050, 0x00000000,
	0x00000054, 0x00000000,
	0x00000058, 0x00000000,
	0x0000005c, 0x00000000,
	0x00000060, 0x00000000,
	0x00000064, 0x00000000,
	0x00000068, 0x00000000,
	0x0000006c, 0x00000000,
	0x00000070, 0x00000000,
	0x00000074, 0x00000000,
	0x00000078, 0x00000000,
	0x0000007c, 0x00000000,
	0x00000080, 0x00000000,
	0x00000084, 0x00000000,
	0x00000088, 0x00000000,
	0x0000008c, 0x00000000,
	0x00000090, 0x00000000,
	0x00000094, 0x00000000,
	0x00000098, 0x00000000,
	0x0000009c, 0x00000000,
	0x00000100, 0x00000000,
	0x00000104, 0x00000000,
	0x00000108, 0x00000000,
	0x0000010c, 0x00000000,
	0x00000110, 0x00000000,
	0x00000114, 0x00000000,
	0x00000118, 0x00000000,
	0x0000011c, 0x00000000
};

void config_fpgaintf_mod(void)
{
	uint32_t val;

	val = 0;
	if (mmio_read_32(AGX_PINMUX_NAND_USEFPGA) & 1)
		val |= AGX_PINMUX_NAND_USEFPGA_VAL;
	if (mmio_read_32(AGX_PINMUX_SDMMC_USEFPGA) & 1)
		val |= AGX_PINMUX_SDMMC_USEFPGA_VAL;
	if (mmio_read_32(AGX_PINMUX_SPIM0_USEFPGA) & 1)
		val |= AGX_PINMUX_SPIM0_USEFPGA_VAL;
	if (mmio_read_32(AGX_PINMUX_SPIM1_USEFPGA) & 1)
		val |= AGX_PINMUX_SPIM1_USEFPGA_VAL;
	mmio_write_32(SOCFPGA_SYSMGR(FPGAINTF_EN_2), val);

	val = 0;
	if (mmio_read_32(AGX_PINMUX_EMAC0_USEFPGA) & 1)
		val |= AGX_PINMUX_EMAC0_USEFPGA_VAL;
	if (mmio_read_32(AGX_PINMUX_EMAC1_USEFPGA) & 1)
		val |= AGX_PINMUX_EMAC1_USEFPGA_VAL;
	if (mmio_read_32(AGX_PINMUX_EMAC2_USEFPGA) & 1)
		val |= AGX_PINMUX_EMAC2_USEFPGA_VAL;
	mmio_write_32(SOCFPGA_SYSMGR(FPGAINTF_EN_3), val);
}


void config_pinmux(handoff *hoff_ptr)
{
	unsigned int i;

	for (i = 0; i < 96; i += 2) {
		mmio_write_32(AGX_PINMUX_PIN0SEL +
			hoff_ptr->pinmux_sel_array[i],
			hoff_ptr->pinmux_sel_array[i+1]);
	}

	for (i = 0; i < 96; i += 2) {
		mmio_write_32(AGX_PINMUX_IO0CTRL +
			hoff_ptr->pinmux_io_array[i],
			hoff_ptr->pinmux_io_array[i+1]);
	}

	for (i = 0; i < 40; i += 2) {
		mmio_write_32(AGX_PINMUX_EMAC0_USEFPGA +
			hoff_ptr->pinmux_fpga_array[i],
			hoff_ptr->pinmux_fpga_array[i+1]);
	}

	for (i = 0; i < 96; i += 2) {
		mmio_write_32(AGX_PINMUX_IO0_DELAY +
			hoff_ptr->pinmux_iodelay_array[i],
			hoff_ptr->pinmux_iodelay_array[i+1]);
	}

	config_fpgaintf_mod();
}

