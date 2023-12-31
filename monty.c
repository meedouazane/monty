#include "monty.h"
/**
 * check_push - check for error in push
 * @secondToken: variable that we will push
 * @line: number of line
 * Return: 0 Success -1 failed.
 */
int check_push(char *secondToken, unsigned int line)
{
	char *inv;

	if (secondToken == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		return (-1);
	}
	strtol(secondToken, &inv, 10);
	if (*inv != '\0' && !isspace(*inv))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		return (-1);
	}
	return (0);
}
/**
 * main_helper - first half of the main.
 * @ins: struct instruction_s.
 * Return: Nothing.
 */
int main_helper(instruction_t ins[])
{
	stack_t *head = NULL;
	char *firstToken, *secondToken, buffer[100];
	int line = 1, i;

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		firstToken = strtok(buffer, " \t\n");
		secondToken = strtok(NULL, " \t\n");
		if (firstToken == NULL)
			continue;
		for (i = 0; ins[i].opcode != NULL; i++)
		{
			if (strcmp(firstToken, ins[i].opcode) == 0)
			{
				if (strcmp(firstToken, "push") == 0)
				{
					if (check_push(secondToken, line) == -1)
						exit(EXIT_FAILURE);
					else
						ins[i].f(&head, atoi(secondToken));
				line++;
				}
				else
				{
					ins[i].f(&head, line);
					line++;
				}
			break;
			}
			else
			if (ins[i + 1].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line, firstToken);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
	free_stack(head);
	return (0);
}
/**
 * main - The main Entery
 * @argc: number of arrguments
 * @argv: arguments being passed
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	instruction_t ins[] = {
		{"pall", _pall},
		{"push", _push},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"swap", _swap},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"rotl", _rotl},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	main_helper(ins);
	return (0);
}
