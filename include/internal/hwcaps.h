// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Interface to retrieve hardware capabilities. It relies on Linux's getauxval
// or `/proc/self/auxval` under the hood.
#ifndef CPU_FEATURES_INCLUDE_INTERNAL_HWCAPS_H_
#define CPU_FEATURES_INCLUDE_INTERNAL_HWCAPS_H_

#include <stdint.h>
#include "cpu_features_macros.h"

CPU_FEATURES_START_CPP_NAMESPACE

// To avoid depending on the linux kernel we reproduce the architecture specific
// constants here.

// http://elixir.free-electrons.com/linux/latest/source/arch/arm64/include/uapi/asm/hwcap.h
#define AARCH64_HWCAP_FP (1UL << 0)
#define AARCH64_HWCAP_ASIMD (1UL << 1)
#define AARCH64_HWCAP_AES (1UL << 3)
#define AARCH64_HWCAP_PMULL (1UL << 4)
#define AARCH64_HWCAP_SHA1 (1UL << 5)
#define AARCH64_HWCAP_SHA2 (1UL << 6)
#define AARCH64_HWCAP_CRC32 (1UL << 7)

// http://elixir.free-electrons.com/linux/latest/source/arch/arm/include/uapi/asm/hwcap.h
#define ARM_HWCAP_SWP       (1 << 0)
#define ARM_HWCAP_HALF      (1 << 1)
#define ARM_HWCAP_THUMB     (1 << 2)
#define ARM_HWCAP_26BIT     (1 << 3)    /* Play it safe */
#define ARM_HWCAP_FAST_MULT (1 << 4)
#define ARM_HWCAP_FPA       (1 << 5)
#define ARM_HWCAP_VFP       (1 << 6)
#define ARM_HWCAP_EDSP      (1 << 7)
#define ARM_HWCAP_JAVA      (1 << 8)
#define ARM_HWCAP_IWMMXT    (1 << 9)
#define ARM_HWCAP_CRUNCH    (1 << 10)
#define ARM_HWCAP_THUMBEE   (1 << 11)
#define ARM_HWCAP_NEON      (1 << 12)
#define ARM_HWCAP_VFPv3     (1 << 13)
#define ARM_HWCAP_VFPv3D16  (1 << 14)   /* also set for VFPv4-D16 */
#define ARM_HWCAP_TLS       (1 << 15)
#define ARM_HWCAP_VFPv4     (1 << 16)
#define ARM_HWCAP_IDIVA     (1 << 17)
#define ARM_HWCAP_IDIVT     (1 << 18)
#define ARM_HWCAP_VFPD32    (1 << 19)   /* set if VFP has 32 regs (not 16) */
/* #define ARM_HWCAP_IDIV      (HWCAP_IDIVA | HWCAP_IDIVT) */ /* No need it as we will report individual items */
#define ARM_HWCAP_LPAE      (1 << 20)
#define ARM_HWCAP_EVTSTRM   (1 << 21)

#define ARM_HWCAP2_AES      (1UL << 0)
#define ARM_HWCAP2_PMULL    (1UL << 1)
#define ARM_HWCAP2_SHA1     (1UL << 2)
#define ARM_HWCAP2_SHA2     (1UL << 3)
#define ARM_HWCAP2_CRC32    (1UL << 4)

// http://elixir.free-electrons.com/linux/latest/source/arch/mips/include/uapi/asm/hwcap.h
#define MIPS_HWCAP_VZ (1UL << 0)
#define MIPS_HWCAP_EVA (1UL << 1)
#define MIPS_HWCAP_HTW (1UL << 2)
#define MIPS_HWCAP_FPU (1UL << 3)
#define MIPS_HWCAP_MIPS32R2 (1UL << 4)
#define MIPS_HWCAP_MIPS32R5 (1UL << 5)
#define MIPS_HWCAP_MIPS64R6 (1UL << 6)
#define MIPS_HWCAP_DSPR1 (1UL << 7)
#define MIPS_HWCAP_DSPR2 (1UL << 8)
#define MIPS_HWCAP_MSA (1UL << 9)

typedef struct {
  uint32_t hwcaps;
  uint32_t hwcaps2;
} HardwareCapabilities;

HardwareCapabilities GetHardwareCapabilities(void);

CPU_FEATURES_END_CPP_NAMESPACE

#endif  // CPU_FEATURES_INCLUDE_INTERNAL_HWCAPS_H_
