#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Node structure for a doubly linked list,
 * used for stack, queue, LIFO, and FIFO operations in the Holberton project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Structure defining an opcode and its associated function,
 * used for stack, queue, LIFO, and FIFO operations in the Holberton project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - Functional data for the project
 * @n_lines: Line counter
 * @stack_head: Head of the stack
 * @fp_struct: File pointer
 * @getl_info: Line content
 * @node_data: Data for the node's value
 *
 * Description: Structure holding functional data for the project,
 * used for stack, queue, LIFO, and FIFO operations in the Holberton project.
 */
typedef struct global_s
{
	FILE *fp_struct;
	stack_t *stack_head;
	char *getl_info;

	int node_data;
	unsigned int n_lines;

} global_t;

/* global Variable */
extern global_t var;

/* execute the matched opcode function */
void execute_opcode(char *opcode);

/* handle the head of a doubly linked list */
void handle_dlist_head(stack_t *head);

/* get the opcode and check if the argument of push in an integer */
char *split_str(char *str_to_split);

/* helper functions */
void is_digit(char *number);
int line_validator(char *str);
size_t dlistint_len(stack_t *h);

/* opcode functions */
void my_push(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);
void my_swap(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_add(stack_t **stack, unsigned int line_number);
void my_nop(stack_t **stack, unsigned int line_number);
void my_sub(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void my_mul(stack_t **stack, unsigned int line_number);
void my_mod(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
