#include <init.h>
#include <kernel.h>
#include <arch/cpu.h>

#ifdef ANDES_V5_L2C_BASE

/* SMU registers */
#define SMU_SYSTEMCFG		0x08

/* SMU SYSTEMCFG bitfields */
#define SMU_SYSTEMCFG_L2C	(1 << 8)

/* L2C registers */
#define L2C_CTRL		0x08

/* L2C Control Register bitfields */
#define L2C_CTRL_CEN		(1 << 0)

/* instr prefetch depth */
#define L2C_CTRL_IPFDPT_0	(0 << 3)
#define L2C_CTRL_IPFDPT_1	(1 << 3)
#define L2C_CTRL_IPFDPT_2	(2 << 3)
#define L2C_CTRL_IPFDPT_3	(3 << 3)

/* data prefetch depth */
#define L2C_CTRL_DPFDPT_0	(0 << 5)
#define L2C_CTRL_DPFDPT_2	(1 << 5)
#define L2C_CTRL_DPFDPT_4	(2 << 5)
#define L2C_CTRL_DPFDPT_8	(3 << 5)

static void l2_cache_enable(void)
{
	volatile uint64_t *l2c_ctrl =
		INT_TO_POINTER(ANDES_V5_L2C_BASE + L2C_CTRL);

	/* Use largest instr/data prefetch depth */
	uint64_t l2c_config = L2C_CTRL_IPFDPT_3 | L2C_CTRL_DPFDPT_8;

	/* Configure L2 cache */
	*l2c_ctrl = l2c_config;

	/* Enable L2 cache */
	*l2c_ctrl = (l2c_config | L2C_CTRL_CEN);
}

static int l2_cache_init(const struct device *dev)
{
	ARG_UNUSED(dev);

	volatile uint32_t *system_cfg =
		INT_TO_POINTER(ANDES_V5_SMU_BASE + SMU_SYSTEMCFG);

	if(!(*system_cfg & SMU_SYSTEMCFG_L2C)) {
		/* This SoC doesn't have L2 cache */
		return -1;
	}

	l2_cache_enable();
	return 0;
}

SYS_INIT(l2_cache_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);

#endif /* defined(ANDES_V5_L2C_BASE) */
