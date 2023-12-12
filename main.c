#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * custom_main - the entry point for Custom Monty Interp
 *
 * @custom_argc: the count of arguments passed to the program
 * @custom_argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int custom_main(int custom_argc, char **custom_argv)
{
	FILE *custom_script_fd = NULL;
	int custom_exit_code = EXIT_SUCCESS;

	if (custom_argc != 2)
		return (usage_error());

	custom_script_fd = fopen(custom_argv[1], "r");
	if (custom_script_fd == NULL)
		return (f_open_error(custom_argv[1]));

	char **custom_op_toks = tokenize_input(custom_script_fd);

	custom_exit_code = run_monty(custom_op_toks);

	fclose(custom_script_fd);
	free(custom_op_toks);
	return (custom_exit_code);
}
