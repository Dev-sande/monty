#include "monty.h"

/**
 *  get_free - Free stack
 *
 *  @head: Stack pointer
 *
 *  Return: Void
 */


void get_free(stack_t *head)
{
	if (head)
	{
		get_free(head->next);
		free(head);
	}
}
