#include "monty.h"
/**
 * _push - pushes an element to the stack.
 * @stack: head of linked list
 * @data: int we want to push
 * Return: always 0
 */
int top = -1;
void _push(stack_t **stack, unsigned int data)
{
	add_dnodeint(stack, data);
	top = top + 1;
}
/**
 * _pall - show element of the stack.
 * @stack: head of linked list
 * @data: int we want to push
 * Return: always 0
 */
void _pall(stack_t **stack, unsigned int data)
{
	(void)data;

	print_dlistint(*stack);
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
	if (top == -1)
	{
		printf("L %d: can't pint, stack empty\n", line);
		EXIT_FAILURE;
	}
	else
		printf("%d\n", h->n);
}