#include <stdlib.h>

#include "reflect.h"

#define JUMP_WITH_STACK(jump_addr, jump_stack) \
	__asm__ volatile ( \
			"movq %[stack], %%rsp\n" /* reset the stack to our pivot */ \
			"xor %%rdx, %%rdx\n" /* zero rdx so no one thinks it's a function pointer for cleanup */ \
			"jmp *%[entry]" /* Up, up, and away! */ \
			: /* None  */ \
			: [stack] "r" (jump_stack), [entry] "r" (jump_addr) \
			: "rdx", "memory" \
			)

inline void __attribute ((noreturn)) jump_with_stack(size_t dest, size_t *stack)
{
	JUMP_WITH_STACK(dest, stack);
	// If we didn't jump, something went wrong
	abort();
}
