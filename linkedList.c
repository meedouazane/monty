#include "monty.h"
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
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: head of a dlistint_t list
 * Return: size of a dlistint_t list
 */
size_t print_dlistint(stack_t *h)
{
	stack_t *current;
	size_t size = 0;

	current = h;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		size++;
		current = current->next;
	}
	return (size);
}
/**
 * free_stack - frees a dlistint_t list.
 * @head: the head of linked list
 * Return: Always EXIT_SUCCESS.
 */
void free_stack(stack_t *head)
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
