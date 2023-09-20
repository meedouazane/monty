#include "monty.h"
/**
 * _mul -  multiplies the second.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _mul(stack_t **stack, unsigned int line)
{
	int mul = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
