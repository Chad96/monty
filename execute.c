#include "monty.h"
#include <string.h>

void clean_up_tokens(void);
unsigned int count_tokens(void);
int is_line_empty(char *line, char *delims);
void (*resolve_opcode(char *op))(stack_t**, unsigned int);
int execute_monty(FILE *script_fd);

/**
 * clean_up_tokens - Frees the global op_tokens array of strings.
 */
void clean_up_tokens(void)
{
	size_t index = 0;

	if (op_toks == NULL)
		return;

	for (index = 0; op_toks[index]; index++)
		free(op_toks[index]);

	free(op_toks);
}

/**
 * count_tokens - Gets the length of the current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int count_tokens(void)
{
	unsigned int tokens_count = 0;

	while (op_toks[tokens_count])
		tokens_count++;
	return (tokens_count);
}

/**
 * is_line_empty - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_line_empty(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * resolve_opcode - Matches an opcode with its corresponding function.
 * @op: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*resolve_opcode(char *op))(stack_t**, unsigned int)
{
	instruction_t op_functions[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_functions[i].opcode; i++)
	{
		if (strcmp(op, op_functions[i].opcode) == 0)
			return (op_functions[i].f);
	}

	return (NULL);
}
