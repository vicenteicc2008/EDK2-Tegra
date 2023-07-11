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

[Components.common]
  Binaries/lipy11/NvTegraPkg/NvOEMHook/NvOEMHook.inf
  Binaries/lipy11/NvTegraPkg/NvTegraDispDxe/NvTegraDispDxe.inf
  Binaries/lipy11/NvTegraPkg/NvTegraVersionDxe/NvTegraVersionDxe.inf
  Binaries/lipy11/NvTegraPkg/NvPmuDxe/NvPmuDxe.inf
  Binaries/lipy11/NvTegraPkg/NvCacheDxe/NvCacheDxe.inf
  Binaries/lipy11/NvTegraTZPkg/NvvRPMBDxe/NvvRPMBDxe.inf
  Binaries/lipy11/NvTegraTZPkg/MorBitDxe/MorBitDxe.inf
  Binaries/lipy11/NvTegraPkg/NvImageVerificationDxe/NvImageVerificationDxe.inf
  Binaries/lipy11/NvTegraPkg/NvRpmbProvisionDxe/NvRpmbProvisionDxe.inf
  Binaries/lipy11/NvTegraPkg/NvHashDxe/NvHashDxe.inf
  Binaries/lipy11/NvTegraPkg/NvAesDxe/NvAesDxe.inf
  Binaries/lipy11/NvTegraPkg/NvSecureEngineDxe/NvSecureEngineDxe.inf
  Binaries/lipy11/NvTegraPkg/RngDxe/RngDxe.inf
  Binaries/lipy11/NvTegraPkg/NvRSADxe/NvRSADxe.inf
  Binaries/lipy11/NvTegraPkg/NvOEMTableDxe/NvOEMTableDxe.inf
  Binaries/lipy11/NvTegraPkg/NvRPMBDxe/NvRPMBDxe.inf
  Binaries/lipy11/NvTegraPkg/NvCrashDumpDxe/NvCrashDumpDxe.inf
  Binaries/lipy11/NvTegraPkg/NvSDMMCDxe/NvSDMMCDxe.inf
  Binaries/lipy11/NvTegraPkg/NvSdmmcInitDxe/NvSdmmcInitDxe.inf
  Binaries/lipy11/NvTegraPkg/NvGateDxe/NvGateDxe.inf
  Binaries/lipy11/NvTegraPkg/NvUARTInitDxe/NvUARTInitDxe.inf
  Binaries/lipy11/NvTegraPkg/SmbusDxe/SmbusDxe.inf
  Binaries/lipy11/NvTegraPkg/NvPmuI2cDxe/NvPmuI2cDxe.inf
  Binaries/lipy11/NvTegraPkg/NvUsbInitDxe/NvUsbInitDxe.inf
  Binaries/lipy11/NvTegraPkg/PciEmulation/PciEmulation.inf
  Binaries/lipy11/NvTegraPkg/NvKbcDxe/NvKbcDxe.inf
  Binaries/lipy11/NvTegraPkg/NvKeyboardDxe/NvKeyboardDxe.inf
  Binaries/lipy11/NvTegraPkg/NvGpioKeyDxe/NvGpioKeyDxe.inf
  Binaries/lipy11/NvMainBoardsPkg/Venus/Dxe/PlatformDxe/PlatformDxe.inf
  Binaries/lipy11/NvMainBoardsPkg/Venus/Dxe/OemDxe/OemDxe.inf
  Binaries/lipy11/NvMainBoardsPkg/Venus/Dxe/OemPowerInfo/OemPowerInfo.inf
  Binaries/lipy11/NvMainBoardsPkg/Venus/Dxe/ECDriverDxe/ECDriverDxe.inf
  Binaries/lipy11/NvTegraPkg/NvGpioDxe/NvGpioDxe.inf
  Binaries/lipy11/NvTegraPkg/NvBoardIDDxe/NvBoardIDDxe.inf
  Binaries/lipy11/NvTegraPkg/NvChipIDDxe/NvChipIDDxe.inf
  Binaries/lipy11/NvTegraPkg/NvFuseDxe/NvFuseDxe.inf
  Binaries/lipy11/NvTegraPkg/NvAhbDxe/NvAhbDxe.inf
  Binaries/lipy11/NvTegraPkg/NvSataInitDxe/NvSataInitDxe.inf
  Binaries/lipy11/NvTegraPkg/SataControllerDxe/SataControllerDxe.inf
  Binaries/lipy11/NvTegraPkg/NvAudioInitDxe/NvAudioInitDxe.inf
  Binaries/lipy11/NvTegraPkg/NvHDMIAudioDxe/NvHDMIAudioDxe.inf
  Binaries/lipy11/NvTegraPkg/NvI2cDxe/NvI2cDxe.inf
  Binaries/lipy11/NvTegraPkg/NvPllDxe/NvPllDxe.inf
  Binaries/lipy11/NvTegraPkg/NvSpiFlashDxe/NvSpiFlashDxe.inf
  Binaries/lipy11/NvTegraPkg/NvSpiDxe/NvSpiDxe.inf
  Binaries/lipy11/NvTegraPkg/NvFreqDxe/NvFreqDxe.inf
  Binaries/lipy11/NvTegraPkg/NvLpxDxe/NvLpxDxe.inf
  Binaries/lipy11/NvTegraPkg/NvESRTDxe/NvESRTDxe.inf
  Binaries/lipy11/NvTegraPkg/DP501Dxe/DP501Dxe.inf
