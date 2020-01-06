#include "monty.h"

/**
 *op_swap - Swaps the top two elements in the stack
 *
 *@stack: The stack
 *@line: Line number
 */
void op_swap(stack_t **stack, unsigned int line)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
