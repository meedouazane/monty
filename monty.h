#ifndef MONTY_H
#define MONTY_H
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
FILE *file;
void free_stack(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
void _add(stack_t **stack, unsigned int line);
void _push(stack_t **stack, unsigned int data);
void _pall(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
int check_push(char *secondToken, unsigned int line);
void _nop(stack_t **stack, unsigned int line);
int main_helper(instruction_t ins[]);
#endif
