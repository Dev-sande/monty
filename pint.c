#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number being executed from the script file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (stack && *stack)
        printf("%d\n", (*stack)->n);
    else
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}

