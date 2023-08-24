#include "monty.h"
/**
  *my_rotl- rotates Pile to the top
  *@head_stk: Pile_head_stk
  *@cntr: line_nbr
  *Return: nothing
 */
void my_rotl(stack_t **head_stk,  __attribute__((unused)) unsigned int cntr)
{
	stack_t *tmp = *head_stk, *aux;

	if (*head_stk == NULL || (*head_stk)->next == NULL)
	{
		return;
	}
	aux = (*head_stk)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head_stk;
	(*head_stk)->next = NULL;
	(*head_stk)->prev = tmp;
	(*head_stk) = aux;
}

