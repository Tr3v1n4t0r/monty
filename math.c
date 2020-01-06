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
		exit(EXIT_FAILURE);
	}
}

/**
 * op_sub - Subtracts the top element of the stack from the second element
 * @stack: The stack
 * @line: Line number
 */
void op_sub(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_div - Divides the second element of the stack by the top element
 * @stack: The stack
 * @line: Line number
 */
void op_div(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n /= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * op_mul - Multiplies the second element of the stack by the top element
 * @stack: The stack
 * @line: Line number
 */
void op_mul(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n *= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * op_mod - Modulus' the second element of the stack by the top element
 * @stack: The stack
 * @line: Line number
 */
void op_mod(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
