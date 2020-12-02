/******************************************************************************
* Copyright (c) Intel Corporation - All rights reserved.                      *
* This file is part of the LIBXSMM library.                                   *
*                                                                             *
* For information on the license, see the LICENSE file.                       *
* Further information: https://github.com/hfp/libxsmm/                        *
* SPDX-License-Identifier: BSD-3-Clause                                       *
******************************************************************************/
/* Alexander Heinecke (Intel Corp.)
******************************************************************************/

#include "generator_packed_gemm_ac_rm_avx_avx2_avx512.h"
#include "generator_packed_gemm_ac_rm_aarch64.h"
#include "libxsmm_main.h"

LIBXSMM_API void libxsmm_generator_packed_gemm_ac_rm( libxsmm_generated_code*         io_generated_code,
                                                      const libxsmm_gemm_descriptor*  i_xgemm_desc,
                                                      const unsigned int              i_packed_width ) {
  if ( (io_generated_code->arch >= LIBXSMM_X86_AVX) &&
       (io_generated_code->arch <= LIBXSMM_X86_ALLFEAT) ) {
    libxsmm_generator_packed_gemm_ac_rm_avx_avx2_avx512( io_generated_code,
                                                         i_xgemm_desc,
                                                         i_packed_width );
  } else if ( (io_generated_code->arch >= LIBXSMM_AARCH64_V81) &&
              (io_generated_code->arch <= LIBXSMM_AARCH64_ALLFEAT) ) {
    libxsmm_generator_packed_gemm_ac_rm_aarch64( io_generated_code,
                                                 i_xgemm_desc,
                                                 i_packed_width );
  } else {
    fprintf( stderr, "PACKED RM AC is only available for AVX/AVX2/AVX512 or AARCH64 at this point\n" );
    exit(-1);
  }
}

