#include "monty.h"
/**
 * _rotl - rotates the stack to the top.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _rotl(stack_t **stack, unsigned int line)
{
	stack_t *tmp1, *tmp2;

	(void)line;
	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	tmp1 = (*stack)->next;
	tmp2 = *stack;

	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp1->prev = NULL;
	tmp2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp2;
	*stack = tmp1;
}
