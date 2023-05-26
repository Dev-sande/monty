#include "monty.h"

/**
 * f_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @head: stack head
 * @counter: line_number
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sub, b;

	aux = *head;
	for (b = 0; aux != NULL; b++)
		aux = aux->next;

	if (b < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = *head;
	sub = aux->next->n - aux->n;
	aux->next->n = sub;
	*head = aux->next;
	free(aux);
}
