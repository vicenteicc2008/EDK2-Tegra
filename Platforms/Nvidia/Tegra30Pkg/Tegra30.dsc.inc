## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|19200000
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|17
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|18
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x50041000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0x50040100

  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x00000030
  gEmbeddedTokenSpaceGuid.PcdInterruptBaseAddress|0x50040100

  gArmPlatformTokenSpaceGuid.PcdCoreCount|4
  gArmPlatformTokenSpaceGuid.PcdClusterCount|1

  gNvidiaTokenSpaceGuid.PcdSmbiosProcessorModel|"Tegra (R) 3 @ 1.70 GHz"
  gNvidiaTokenSpaceGuid.PcdSmbiosProcessorRetailModel|"T30-A03"

  gNvidiaTokenSpaceGuid.PcdUefiMemPoolBase|0x90000000
  gNvidiaTokenSpaceGuid.PcdUefiMemPoolSize|0x03C00000

[LibraryClasses.common]
  PlatformPrePiLib|Tegra30Pkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf

[Components.common]
  Tegra30Pkg/Drivers/PlatformSmbiosDxe/PlatformSmbiosDxe.inf

!include NvidiaPkg/Nvidia.dsc.inc