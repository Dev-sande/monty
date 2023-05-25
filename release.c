#include "monty.h"

/**
 * free_stack - source file min function
 * @head: stack header
*/

void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

