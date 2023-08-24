#include "monty.h"

/**
 * add_nod - add  node to the head_pile
 * @head_stk: head  pile
 * @n: new_val
 * Return: NULL
*/
void add_nod(stack_t **head_stk, int n)
{

	stack_t *new_node, *aux;

	aux = *head_stk;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head_stk;
	new_node->prev = NULL;
	*head_stk = new_node;
}
