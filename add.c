#include "monty.h"

/**
 * my_add - adds the top elements of Pile.
 * @head_stk: stack head_pile
 * @cntr: line_nbr
 * Return: nULL
*/
void my_add(stack_t **head_stk, unsigned int cntr)
{
	stack_t *P;
	int len = 0, aux;

	P = *head_stk;
	while (P)
	{
		P = P->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, PIlle too short\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}

	P = *head_stk;
	aux = P->n + P->next->n;
	P->next->n = aux;
	*head_stk = P->next;
	free(P);
}
