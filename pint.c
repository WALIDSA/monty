#include "monty.h"
/**
 * my_pint - display the_top
 * @head_stk: Pile_head_stk
 * @cntr: line_nbr
 * Return: NUKLL
*/
void my_pint(stack_t **head_stk, unsigned int cntr)
{
	if (*head_stk == NULL)
	{
		fprintf(stderr, "L%u: can not pint, stack empty\n", cntr);
		fclose(bus.file);
		free(bus.contnt);
		free_stack(*head_stk);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head_stk)->n);
}
