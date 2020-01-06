#include "monty.h"

/**
 *op_add - Adds the top 2 elements of a stack
 *
 *@stack: The stack
 *@line: Line number
 */
void op_add(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);

	}
	else
	{
		dprintf(STDERR_FILENO,
			"L%u: can't add, stack too short\n", line);
		free_all(stack);
		exit(1);
	}
}
