#include <Library/ArmGicLib.h>
#include <Library/ArmLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/PrintLib.h>
#include <Library/SerialPortLib.h>
#include <Library/PlatformPrePiLib.h>

#include "PlatformUtils.h"

VOID UartInit(VOID)
{
  SerialPortInitialize();

  DEBUG((EFI_D_INFO, "\nEDK2 UEFI on %a (Arm)\n", (VOID *)FixedPcdGetPtr(PcdSmbiosSystemModel)));
  DEBUG(
      (EFI_D_INFO, "Firmware version %s built %a %a\n\n",
       (CHAR16 *)PcdGetPtr(PcdFirmwareVersionString), __TIME__, __DATE__));
}

VOID PlatformInitialize(VOID)
{
  // Initialize UART Serial
  UartInit();

  // Initialize GIC
  MmioWrite32(
      GICR_WAKER_CURRENT_CPU,
      (MmioRead32(GICR_WAKER_CURRENT_CPU) & ~GIC_WAKER_PROCESSORSLEEP));
}
