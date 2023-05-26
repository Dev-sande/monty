#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @head: stack head
 * @counter: line_number
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *first, *second;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *head;
		second = first->next;
		second->n %= first->n;
		*head = second;
		(*head)->prev = NULL;
		free(first);
	}
}
