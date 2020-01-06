#include "monty.h"

/**
 *get_op - Determines which operation to run
 *
 *@stack: The stack
 *@s: String to compare
 *@line: Line number
 *
 *Return: The executed function name
 */
void (*get_op(stack_t **stack, char *s, int line))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		/**
		 *{"pint", op_pint},
		 */{"pop", op_pop},
		/**
		 *{"swap", op_swap},
		 */{"add", op_add},
		{"nop", op_nop},
		/**
		 *{"sub", op_sub},
		 *{"div", op_div},
		 *{"mul", op_mul},
		 *{"mod", op_mod},
		 *{"#", op_nop},
		 *{"pchar", op_pchar},
		 *{"pstr", op_pstr},
		 *{"rotl", op_rotl},
		 *{"rotr", op_rotr},
		 *{"stack", op_stack},
		 *{"queue", op_queue},
		 */{NULL, NULL}
	};
	int i = 0;
	unsigned int j;

	while (ops[i].opcode)
	{
		for (j = 0; j < strlen(s); j++)
		{
			if (s[j] == '\n')
				s[j] = '\0';
		}
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, s);
	free_all(stack);
	exit(EXIT_FAILURE);
}
