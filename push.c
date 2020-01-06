#include "monty.h"

/**
 *op_push - Pushes an element to the stack
 *
 *@stack: The stack
 *@line: Line number
 */
void op_push(stack_t **stack, unsigned int line)
{
	char argbuf[128] = "";
	char *arg = argbuf;
	int argument;
	unsigned int i;

	arg = strtok(NULL, " \t");
	if (arg)
	{
		if (arg[0] == '\n')
			push_error(stack, line);
		for (i = 0; i < strlen(arg); i++)
		{
			if (!isdigit(arg[i]) && arg[0] != '-' && arg[i] != '\n')
				push_error(stack, line);
		}
		argument = atoi(arg);
	}
	else
		push_error(stack, line);
	add_stack(stack, argument);
}

/**
 *push_error - Prints an error and exits
 *
 *@stack: The stack
 *@line: Line number
 */
void push_error(stack_t **stack, unsigned int line)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
	free_all(stack);
	exit(1);
}

/**
 *add_stack - Adds a node to the stack
 *
 *@stack: The stack
 *@argument: Value of node
 */
void add_stack(stack_t **stack, int argument)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(1);
	}
	new->n = argument;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
