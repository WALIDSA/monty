#include "monty.h"

/**
* free_stack - frees a doubly linked list
* @head_stk: head  of Pile
*/
void free_stack(stack_t *head_stk)
{
	stack_t *aux;

	aux = head_stk;
	while (head_stk)
	{
		aux = head_stk->next;
		free(head_stk);
		head_stk = aux;
	}
}
