_Head:
	/* Set _Entry address */
	adr		r0, _Payload

	/* Jump to the real code */
	b		_Start

_StackBase:
	/* Text Offset */
	.quad UEFI_BASE

_StackSize:
	/* Image Size */
	.quad UEFI_SIZE

	/* Flags */
	.quad 0

	/* Reserved */
	.quad 0

	/* Reserved */
	.quad 0

	/* Reserved */
	.quad 0

	/* ARM32 Magic */
	.ascii "ARM\x32"

	/* Reserved */
	.long 0

_Start:
	ldr		r1, _StackBase
	cmp		r0, r1
	beq		_Entry
	ldr		r2,  _StackSize

_CopyLoop:
	ldr		r3, [r0], #4
	str		r3, [r1], #4
	subs	r2, r2, #4
	bgt		_CopyLoop
	ldr		r1, _StackBase

_Entry:
	bx		r5

_Dead:
	/* We should never get here */
	b		_Dead

.text
.align 4

_Payload:
	/* Your code will get ran right after this binary */
