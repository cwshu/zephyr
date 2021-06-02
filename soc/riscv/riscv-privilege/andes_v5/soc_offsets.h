#ifndef SOC_RISCV_ANDES_V5_SOC_OFFSETS_H_
#define SOC_RISCV_ANDES_V5_SOC_OFFSETS_H_

#ifdef CONFIG_RISCV_SOC_OFFSETS

/* Andes V5 specific registers. */
#if defined(CONFIG_SOC_ANDES_V5_PFT) && defined(__riscv_dsp)
	#define GEN_SOC_OFFSET_SYMS()			\
		GEN_OFFSET_SYM(soc_esf_t, mxstatus);	\
		GEN_OFFSET_SYM(soc_esf_t, ucode)

#elif defined(CONFIG_SOC_ANDES_V5_PFT)
	#define GEN_SOC_OFFSET_SYMS()			\
		GEN_OFFSET_SYM(soc_esf_t, mxstatus)

#elif defined(__riscv_dsp)
	#define GEN_SOC_OFFSET_SYMS()			\
		GEN_OFFSET_SYM(soc_esf_t, ucode)

#endif

#endif /* CONFIG_RISCV_SOC_OFFSETS */

#endif /* SOC_RISCV_ANDES_V5_SOC_OFFSETS_H_*/
