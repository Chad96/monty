#include "monty.h"
/**
* exec_op - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exec_op(char *content, stack_t **stack,
unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_values}, {"pall", pall_values}, {"pint", pint_values},
				{"pop", pop_values},
				{"swap", swap_values},
				{"add", add_values},
				{"nop", nop_values},
				{"sub", sub_values},
				{"div", divide_values},
				{"mul", mul_values},
				{"mod", mod_values},
				{"pchar", print_char},
				{"pstr", printstr},
				{"rotl", rotl_op},
				{"rotr", rotr_op},
				{"queue", queue_values},
				{"stack", stack_values},
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
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		release_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
