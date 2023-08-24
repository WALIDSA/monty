#include "monty.h"

/**
 * my_push - appends a new node to the stack
 * @stack: pointer to the stack's head
 * @line_number: current line number
 *
 * Return: void.
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	line_number = line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = var.node_data;

	new->next = *stack;
	new->prev = NULL;
	if ((*stack) != NULL)
	{
		(*stack)->prev = new;
	}

	*stack = new;
}

/**
 * my_pall - prints all the values on the stack
 * @stack: pointer to the stack's head
 * @line_number: current line number
 *
 * Return: void.
 */
void my_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *printer_aux = *stack;

	printer_aux = *stack;
	line_number = line_number;

	while (printer_aux != NULL)
	{
		printf("%d\n", printer_aux->n);
		printer_aux = printer_aux->next;
	}
}

/**
 * my_pint - prints the value at the top of the stack
 * @stack: pointer to the stack's head
 * @line_number: current line number
 *
 * Return: void.
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(var.getl_info);
		fclose(var.fp_struct);
		handle_dlist_head((*stack));
		exit(EXIT_FAILURE);
	}

	printf("%d\n", ((*stack))->n);
}

/**
 * my_swap - swaps the top two elements of the stack
 * @stack: pointer to the stack's head
 * @line_number: current line number
 *
 * Return: void.
 */
void my_swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(var.getl_info);
		fclose(var.fp_struct);
		handle_dlist_head((*stack));
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
