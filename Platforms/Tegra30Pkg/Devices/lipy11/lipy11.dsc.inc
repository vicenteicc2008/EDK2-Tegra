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

[LibraryClasses.common]
  PlatformMemoryMapLib|Tegra30Pkg/Devices/lipy11/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000         # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x80000000         # 2GB Size

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x00003000

  # PrePi Stack
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x00000000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00020000      # 128K stack

  # UART
  gNvidiaTokenSpaceGuid.PcdDebugUartPortBase|0x70006000

  # Device Info
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemVendor|"Lenovo"
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemModel|"IdeaPad Yoga 11"
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemRetailModel|"lipy11"
  gNvidiaTokenSpaceGuid.PcdSmbiosSystemRetailSku|"IdeaPad_Yoga_11_lipy11"
  gNvidiaTokenSpaceGuid.PcdSmbiosBoardModel|"IdeaPad Yoga 11"

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|1366
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|768
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|1366
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|768
