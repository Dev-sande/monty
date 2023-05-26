#include "monty.h"

/**
 * f_mul -  multiplies the second top element of the
 * stack with the top element of the stack.
 * @head: stack head
 * @counter: line_number
 */

void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *first, *second;

	if ((*head == NULL) || ((*head)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		first = *head;
		second = first->next;
		second->n *= first->n;
		*head = second;
		(*head)->prev = NULL;
		free(first);
	}
}
