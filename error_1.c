#include "monty.h"

int display_usage_error(void);
int handle_malloc_error(void);
int handle_file_open_error(char *filename);
int handle_unknown_opcode_error(char *opcode, unsigned int line_number);
int handle_no_integer_error(unsigned int line_number);

/**
 * display_usage_error - Prints usage error messages.
 * Return: (EXIT_FAILURE) always.
 */
int display_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * handle_malloc_error - Prints malloc error messages.
 * Return: (EXIT_FAILURE) always.
 */
int handle_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * handle_file_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 * Return: (EXIT_FAILURE) always.
 */
int handle_file_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * handle_unknown_opcode_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int handle_unknown_opcode_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * handle_no_integer_error - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE) always.
 */
int handle_no_integer_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
