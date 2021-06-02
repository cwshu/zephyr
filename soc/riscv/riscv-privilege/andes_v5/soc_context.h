#ifndef SOC_RISCV_ANDES_V5_SOC_CONTEXT_H_
#define SOC_RISCV_ANDES_V5_SOC_CONTEXT_H_

#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE

/* Andes V5 specific registers. */
#if defined(CONFIG_SOC_ANDES_V5_PFT) && defined(__riscv_dsp)
	#define SOC_ESF_MEMBERS 			\
		uint32_t mxstatus;				\
		uint32_t ucode				\

	#define SOC_ESF_INIT				\
		0,				\
		0

#elif defined(CONFIG_SOC_ANDES_V5_PFT)
	#define SOC_ESF_MEMBERS 			\
		uint32_t mxstatus

	#define SOC_ESF_INIT				\
		0

#elif defined(__riscv_dsp)

	#define SOC_ESF_MEMBERS 			\
		uint32_t ucode

	#define SOC_ESF_INIT				\
		0

#endif

#endif /* CONFIG_RISCV_SOC_CONTEXT_SAVE */

#endif /* SOC_RISCV_ANDES_V5_SOC_CONTEXT_H_ */
