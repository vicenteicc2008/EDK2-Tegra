## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#  Copyright (c) 2022, Xilin Wu. All rights reserved.
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
  PLATFORM_NAME                  = Venus
  PLATFORM_GUID                  = 6ae59ad6-857a-4992-b50f-454cbd975e19
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/VenusPkg
  SUPPORTED_ARCHITECTURES        = ARM
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = VenusPkg/Venus.fdf

[LibraryClasses.common]
  PlatformMemoryMapLib|VenusPkg/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf
  PlatformPeiLib|VenusPkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  EarlyDisplayInitLib|VenusPkg/Library/EarlyDisplayInitLib/EarlyDisplayInitLib.inf

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000         # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x80000000         # 2GB Size

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x00003000

  # PrePi Stack
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x00000000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00020000      # 128K stack

  # UART
  gNvidiaTokenSpaceGuid.PcdDebugUartPortBase|0x70006000

  # Simple FrameBuffer
  gNvidiaTokenSpaceGuid.PcdMipiFrameBufferWidth|1366
  gNvidiaTokenSpaceGuid.PcdMipiFrameBufferHeight|768
  gNvidiaTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|24

  # Device Info
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemVendor|"Lenovo"
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemModel|"IdeaPad Yoga 11"
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemRetailModel|"Venus"
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemRetailSku|"IdeaPad_Yoga_11_Venus"
  gNvidiaTokenSpaceGuid.PcdSmbiosBoardModel|"IdeaPad Yoga 11"

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1366
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|768
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1366
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|768

!include Tegra30Pkg/Tegra30.dsc.inc
