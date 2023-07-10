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

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = Tegra30
  PLATFORM_GUID                  = 32676C1B-7B74-47A6-9C1C-5E0C1D5E1F7E
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/Tegra30Pkg
  SUPPORTED_ARCHITECTURES        = ARM
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = Tegra30Pkg/Tegra30.fdf

!include Tegra30Pkg/Devices/$(TARGET_DEVICE)/$(TARGET_DEVICE).dsc.inc
!include NvidiaPkg/Nvidia.dsc.inc

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
  PlatformPeiLib|Tegra30Pkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  PlatformPrePiLib|Tegra30Pkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf

[Components.common]
  Tegra30Pkg/Drivers/PlatformSmbiosDxe/PlatformSmbiosDxe.inf
