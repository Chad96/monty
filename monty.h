#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void free_custom_stack(stack_t **custom_stack);
int calculate_required_buffer_length(unsigned int number, unsigned int base);
int initialize_custom_stack(stack_t **custom_stack);
int check_custom_mode(stack_t *custom_stack);
int check_mode(stack_t *stack);
void clean_up_tokens(void);
void free_tokens(void);

unsigned int token_arr_len(void);
unsigned int count_tokens(void);
unsigned int absolute_value(int value);

int run_monty(char **custom_op_toks);
int run_monty(FILE *script_fd);
int custom_main(int custom_argc, char **custom_argv);
void set_op_tok_error(int error_code);


/* OPCODE FUNCTIONS */
void custom_monty_push(stack_t **custom_stack, unsigned int custom_line_number);
void custom_monty_pall(stack_t **custom_stack, unsigned int custom_line_number);
void custom_monty_pint(stack_t **custom_stack, unsigned int custom_line_number);
void custom_monty_pop(stack_t **custom_stack, unsigned int custom_line_number);
void custom_monty_swap(stack_t **custom_stack, unsigned int custom_line_number);

void custom_add(stack_t **stack, unsigned int line_number);
void custom_sub(stack_t **stack, unsigned int line_number);
void custom_div(stack_t **stack, unsigned int line_number);
void custom_mul(stack_t **stack, unsigned int line_number);
void custom_mod(stack_t **stack, unsigned int line_number);

void custom_nop(stack_t **stack, unsigned int line_number);
void custom_pchar(stack_t **stack, unsigned int line_number);
void custom_pstr(stack_t **stack, unsigned int line_number);


void custom_rotl(stack_t **custom_stack, unsigned int custom_line_number);
void custom_rotr(stack_t **custom_stack, unsigned int custom_line_number);
void custom_stack_mode(stack_t **custom_stack, unsigned int custom_line_number);
void custom_queue_mode(stack_t **custom_stack, unsigned int custom_line_number);

void clean_up_tokens(void);
void (*resolve_opcode(char *op))(stack_t**, unsigned int);
void fill_buffer_with_number_base(unsigned int number, unsigned int base,

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char *convert_int_to_string(int number);
char **custom_strtow(char *input_str, char *delimiters);
char *get_int(int n);
char *get_next_word(char *input_str, char *delimiters);
char **tokenize_input(FILE *custom_script_fd);
char *buffer, int buffer_size);

/* ERROR MESSAGES & ERROR CODES */
int display_usage_error(void);
int handle_malloc_error(void);
int handle_file_open_error(char *filename);
int f_open_error(char *filename);
int handle_unknown_opcode_error(char *opcode, unsigned int line_number);
int handle_no_integer_error(unsigned int line_number);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int execute_monty(FILE *script_fd);
int is_delimiter(char ch, char *delimiters);
int is_line_empty(char *line, char *delims);
int get_word_length(char *input_str, char *delimiters);
int get_word_count(char *input_str, char *delimiters);

#endif /* __MONTY_H__ */
