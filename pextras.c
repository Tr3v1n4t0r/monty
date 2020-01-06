#include "monty.h"

/**
 * op_pchar - Prints the char at the top of the stack
 * @stack: The stack
 * @line: Line number
 */
void op_pchar(stack_t **stack, unsigned int line)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 32 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%c\n", (*stack)->n);
	}
}

/**
 * op_pstr - Prints the string starting at the top of the stack
 * @stack: The stack
 * @line: Line number
 */
void op_pstr(stack_t **stack, unsigned int line)
{
	stack_t *here = *stack;

	(void) line;

	while (here)
	{
		if (here->n > 0 && here->n < 128)
		{
			if (here->n > 31 && here->n < 127)
				putchar(here->n);
			here = here->next;
		}
		else
			break;
	}
	printf("\n");
}
