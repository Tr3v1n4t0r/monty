#include "monty.h"

/**
 *op_pop - Removes the top element of the stack
 *
 *@stack: The stack
 *@line: Line number
 */
void op_pop(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
