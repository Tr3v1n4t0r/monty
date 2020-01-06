#include "monty.h"

/**
 *op_pall - Prints the stack
 *
 *@stack: The stack
 *@line: Line number
 */
void op_pall(stack_t **stack, unsigned int line)
{
	stack_t *here = *stack;

	(void) line;

	while (here)
	{
		printf("%d\n", here->n);
		here = here->next;
	}
}
