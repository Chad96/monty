#include "monty.h"

/**
 * set_op_tok_error - Sets the last element of op_toks to be an error code.
 * @err_code: The error code to store as a string in op_toks.
 *
 * Description: This function sets the last element of the op_toks array
 * to be a string representation of the given error code.
 */

void set_op_tok_error(int err_code)
{
	int toks_length = 0, index = 0;
	char *err_str = NULL;
	char **new_tokens = NULL;

	toks_length = token_arr_len();
	new_tokens = malloc(sizeof(char *) * (toks_length + 2));

	if (!op_toks)
	{
		malloc_error();
		return ();
	}
	while (index < toks_length)
	{
		new_tokens[index] = op_toks[index];
		index++;
	}
	err_str = get_int(err_code);
	if (!err_str)
	{
		free(new_tokens);
		malloc_error();
		return ();
	}
	new_tokens[index++] = err_str;
	new_tokens[index] = NULL;
	free(op_toks);
	op_toks = new_tokens;
}
