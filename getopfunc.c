#include "monty.h"

/**
 * get_op_func - selects correct function to implement opcode
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 */
void get_op_func(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
	{"push", op_push},
	{"pall", op_pall},
	{"pint", op_pint},
	{"pop", op_pop},
	{"swap", op_swap},
	{"add", op_add},
	{"nop", op_nop},
	{"sub", op_sub},
	{NULL, NULL}
	};
	int i;

	for (i = 0; i < 8; i++)
	{
		if (strcmp(var.optoks[0], ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	if (i == 8)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, var.optoks[0]);
		exit(EXIT_FAILURE);
	}
}
