#include "monty.h"

/**
 * my_div - Divide the top two elements of the stack
 * @stack: Pointer to the stack's head
 * @line_number: Current line number
 *
 * Return: Number of nodes
 */
void my_div(stack_t **stack, unsigned int line_number)
{
	size_t n = 0;
	stack_t *temp = *stack;

	line_number = line_number;
	n = dlistint_len(var.stack_head);
	if (n < 2)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: can't div, stack too short\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: division by zero\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n / (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * my_mul - Multiply the top two elements of the stack
 * @stack: Pointer to the stack's head
 * @line_number: Current line number
 *
 * Return: Number of nodes
 */
void my_mul(stack_t **stack, unsigned int line_number)
{
	size_t n = 0;
	stack_t *temp = *stack;

	line_number = line_number;
	n = dlistint_len(var.stack_head);
	if (n < 2)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: can't mul, stack too short\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n * (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * my_mod - Calculate the modulus of the top two elements of the stack
 * @stack: Pointer to the stack's head
 * @line_number: Current line number
 *
 * Return: Number of nodes
 */
void my_mod(stack_t **stack, unsigned int line_number)
{
	size_t n = 0;
	stack_t *temp = *stack;

	line_number = line_number;
	n = dlistint_len(var.stack_head);
	if (n < 2)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: can't mod, stack too short\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		handle_dlist_head(var.stack_head);
		free(var.getl_info);
		fclose(var.fp_struct);
		fprintf(stderr, "L%u: division by zero\n", var.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n % (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}
