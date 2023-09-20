#include "monty.h"
stack_t *head = NULL;
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: head of linked list
 * @n: node that we'll add
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		EXIT_FAILURE;
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * free_stack - frees a dlistint_t list.
 * @head: the head of linked list
 * Return: Always EXIT_SUCCESS.
 */
void free_stack(void)
{
	stack_t *current;
	stack_t *temp;

	current = head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
