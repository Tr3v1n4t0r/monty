#include "monty.h"

/**
 *main - Entry point
 *
 *@argc: Argument count
 *@argv: Argument vector
 *
 *Return: 0 for success, else 1
 */
int main(int argc, char **argv)
{
	char buffer[1024];
	char a[128] = "";
	char *token = a;
	stack_t *stack = NULL;
	unsigned int line = 1;
	FILE *fp;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), fp))
	{
		token = strtok(buffer, " \t");
		if (token[0] == '#')
			op_nop(&stack, line);
		else if (token[0] != '\n')
			get_op(&stack, token, line)(&stack, line);
		line++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);
}
