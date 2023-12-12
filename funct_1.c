#include "monty.h"

void custom_monty_push(stack_t **custom_stack,
		unsigned int custom_line_number);
void custom_monty_pall(stack_t **custom_stack,
		unsigned int custom_line_number);
void custom_monty_pint(stack_t **custom_stack,
		unsigned int custom_line_number);
void custom_monty_pop(stack_t **custom_stack, unsigned int custom_line_number);
void custom_monty_swap(stack_t **custom_stack,
		unsigned int custom_line_number);

/**
 * custom_monty_push - Pushes a value to a stack_t linked list.
 * @custom_stack: A pointer to the top mode node of a stack_t linked list.
 * @custom_line_number: The current working line number
 */
void custom_monty_push(stack_t **custom_stack, unsigned int custom_line_number)
{
	stack_t *custom_tmp, *custom_new;
	int i;

	custom_new = malloc(sizeof(stack_t));

	if (custom_new == NULL)
	{
		set_op_tok_error(malloc_error());
		return ();
	}
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(custom_line_number));
		return ();
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(custom_line_number));
			return ();
		}
	}
	custom_new->n = atoi(op_toks[1]);

	if (check_mode(*custom_stack) == STACK) /* STACK mode insert at front */
	{
		custom_tmp = (*custom_stack)->next;
		custom_new->prev = *custom_stack;
		custom_new->next = custom_tmp;
		if (custom_tmp)
			custom_tmp->prev = custom_new;
		(*custom_stack)->next = custom_new;
		else /* QUEUE mode insert at end */
		{
		custom_tmp = *custom_stack;
		while (custom_tmp->next)
			custom_tmp = custom_tmp->next;
		custom_new->prev = custom_tmp;
		custom_new->next = NULL;
		custom_tmp->next = custom_new;
		}
	}

/**
 * custom_monty_pall - Prints the values of a stack_t linked list.
 * @custom_stack: A pointer to the top mode node of a stack_t linked list.
 * @custom_line_number: The current working line number
 */
void custom_monty_pall(stack_t **custom_stack, unsigned int custom_line_number)
{
	stack_t *custom_tmp = (*custom_stack)->next;

	while (custom_tmp)
	{
		printf("%d\n", custom_tmp->n);
		custom_tmp = custom_tmp->next;
	}
	(void)custom_line_number;
}

/**
 * custom_monty_pint - Prints the top value of a stack_t linked list.
 * @custom_stack: A pointer to the top mode node of a stack_t linked list.
 * @custom_line_number: The current working line number
 */
void custom_monty_pint(stack_t **custom_stack, unsigned int custom_line_number)
{
	if ((*custom_stack)->next == NULL)
	{
		set_op_tok_error(pint_error(custom_line_number));
		return ();
	}
	printf("%d\n", (*custom_stack)->next->n);
}

/**
 * custom_monty_pop - Removes the top value element of a stack_t linked list.
 * @custom_stack: A pointer to the top mode node of a stack_t linked list.
 * @custom_line_number: The current working line number
 */
void custom_monty_pop(stack_t **custom_stack, unsigned int custom_line_number)
{
	stack_t *custom_next = NULL;

	if ((*custom_stack)->next == NULL)
	{
		set_op_tok_error(pop_error(custom_line_number));
		return ();
	}
	custom_next = (*custom_stack)->next->next;
	free((*custom_stack)->next);
	if (custom_next)
		custom_next->prev = *custom_stack;
	(*custom_stack)->next = custom_next;
}

/**
 * custom_monty_swap - Swaps the top two value elements
 * @custom_stack: A pointer to the top mode node of a stack_t linked list.
 * @custom_line_number: The current working line number
 */
void custom_monty_swap(stack_t **custom_stack, unsigned int custom_line_number)
{
	stack_t *custom_tmp;

	if ((*custom_stack)->next == NULL || (*custom_stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(custom_line_number, "swap"));
		return ();
	}

	custom_tmp = (*custom_stack)->next->next;
	(*custom_stack)->next->next = custom_tmp->next;
	(*custom_stack)->next->prev = custom_tmp;
	if (custom_tmp->next)
		custom_tmp->next->prev = (*custom_stack)->next;
	custom_tmp->next = (*custom_stack)->next;
	custom_tmp->prev = *custom_stack;
	(*custom_stack)->next = custom_tmp;
}
