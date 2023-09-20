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

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (stack == NULL || (*stack)->next == NULL)
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
/**
 * _sub - sub the top two elements of the stack.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _sub(stack_t **stack, unsigned int line)
{
	int sub = 0;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: head of linked list
 * @line: number of line
 * Return: always 0
 */
void _swap(stack_t **stack, unsigned int line)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	(*stack)->next = current->next;
	if (current->next != NULL)
		current->next->prev = *stack;
	current->next = *stack;
	(*stack)->prev = current;
	current->prev = NULL;
	*stack = current;
}
