#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack.
 * @head: stack head
 * @counter: line_number
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *new_node;

	new_node = *head;
	(void)counter;

	while (new_node)
	{
		if (new_node->n > 127 || new_node->n <= 0)
		{
			break;
		}
		printf("%c", new_node->n);
		new_node = new_node->next;
	}
	printf("\n");
}
