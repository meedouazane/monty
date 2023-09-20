#include "monty.h"
/**
 * _nop -  removes the top element of the stack.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
/**
 * _add - adds the top two elements of the stack.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _add(stack_t **stack, unsigned int line)
{
	int add = 0;

	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
