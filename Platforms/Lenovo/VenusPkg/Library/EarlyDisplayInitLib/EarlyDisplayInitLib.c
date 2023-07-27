#include <PiDxe.h>

#include <Library/ArmLib.h>
#include <Library/CacheMaintenanceLib.h>
#include <Library/HobLib.h>

VOID
InitializeBridge(VOID)
{
	// Add DP501 Init Part here!
}

VOID
InitializeBacklight(VOID)
{
	// Add PWM Init Part here!
}

VOID
InitializePanel(VOID)
{
	// Add LCD Init Part here!
}

VOID
InitializeFrameBuffer(VOID)
{
	// Add Frame Buffer Init Part here!
}

VOID
InitializeDisplay(VOID)
{
	// Initialize DP501
	InitializeBridge();

	// Initialize PWM
	InitializeBacklight();

	// Initialize LCD
	InitializePanel();

	// Initialize Frame Buffer
	InitializeFrameBuffer();
}