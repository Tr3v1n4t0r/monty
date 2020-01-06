#include "monty.h"

/**
 *op_pint - Prints the value at the top of the stack
 *
 *@stack: The stack
 *@line: Line number
 */
void op_pint(stack_t **stack, unsigned int line)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		free_all(stack);
		exit(1);
	}
}
