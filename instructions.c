#include "monty.h"

/**
 * execute - used to run operation codes
 * @content: content
 * @stack: double pointer to the head of the stack
 * @counter: counter
 * @file: file pointer
 * Return: Nothing
 */
int execute(char *content, stack_t **head, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"pint", &pint},
        {"pop", &f_pop},
        {"swap", &f_swap},
        {"add", &f_add},
	{"sub", &f_sub},
	{"div", &f_div},
	{"mod", &f_mod},
	{"pchar", &f_pchar},
	{"mul", &f_mul},
        {"nop", &f_nop},
        {"push", &f_push},
        {"pall", &f_pall},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *op;

    op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return (0);

    bus.arg = strtok(NULL, " \n\t");

    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].f(head, counter);
            return (0);
        }
        i++;
    }

    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    return (1);
}

