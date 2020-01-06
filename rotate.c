#include "monty.h"

/**
 * op_rotl - Rotates the stack to the top
 * @stack: The stack
 * @line: Line number
 */
void op_rotl(stack_t **stack, unsigned int line)
{
	stack_t *here = *stack;

	(void) line;

	if (*stack && (*stack)->next)
	{
		while (here->next)
			here = here->next;
		here->next = *stack;
		(*stack)->prev = here;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}

/**
 * op_rotr - Rotates the stack to the bottom
 * @stack: The stack
 * @line: Line number
 */
void op_rotr(stack_t **stack, unsigned int line)
{
	stack_t *here = *stack;

	(void) line;

	if (*stack && (*stack)->next != NULL)
	{
		while (here->next != NULL)
			here = here->next;
		here->next = *stack;
		(*stack)->prev = here;
		here->prev->next = NULL;
		here->prev = NULL;
		*stack = here;
	}
}
