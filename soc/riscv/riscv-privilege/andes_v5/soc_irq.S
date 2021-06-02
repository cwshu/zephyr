#include <offsets.h>
#include <toolchain.h>

#include <soc.h>

/* Exports */
#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE
GTEXT(__soc_save_context)
GTEXT(__soc_restore_context)
#endif

#ifdef CONFIG_RISCV_SOC_CONTEXT_SAVE

SECTION_FUNC(exception.other, __soc_save_context)

#ifdef CONFIG_SOC_ANDES_V5_PFT
	csrr t0, NDS_MXSTATUS
#endif
#ifdef __riscv_dsp
	csrr t1, NDS_UCODE
#endif

#ifdef CONFIG_SOC_ANDES_V5_PFT
	sw t0, __soc_esf_t_mxstatus_OFFSET(a0)
#endif
#ifdef __riscv_dsp
	sw t1, __soc_esf_t_ucode_OFFSET(a0)
#endif
	ret

SECTION_FUNC(exception.other, __soc_restore_context)

#ifdef CONFIG_SOC_ANDES_V5_PFT
	lw t0, __soc_esf_t_mxstatus_OFFSET(a0)
#endif
#ifdef __riscv_dsp
	lw t1, __soc_esf_t_ucode_OFFSET(a0)
#endif

#ifdef CONFIG_SOC_ANDES_V5_PFT
	csrw NDS_MXSTATUS, t0
#endif
#ifdef __riscv_dsp
	csrw NDS_UCODE, t1
#endif
	ret

#endif /* CONFIG_RISCV_SOC_CONTEXT_SAVE */
