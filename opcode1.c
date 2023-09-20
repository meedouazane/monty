#include "monty.h"
/**
 * _push - pushes an element to the stack.
 * @stack: head of linked list
 * @data: int we want to push
 * Return: always 0
 */
void _push(stack_t **stack, unsigned int data)
{
	add_dnodeint(stack, data);
}
/**
 * _pall - show element of the stack.
 * @stack: head of linked list
 * @line: int we want to push
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *current;

	(void)line;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint -  prints the value at the top of the stack.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _pint(stack_t **stack, unsigned int line)
{
	stack_t *h;

	h = *stack;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", h->n);
}
/**
 * _pop -  removes the top element of the stack.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	free(current);
}
