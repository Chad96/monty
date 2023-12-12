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
int initialize_custom_stack(stack_t **custom_stack);
int check_custom_mode(stack_t *custom_stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
unsigned int count_tokens(void);
int run_monty(char **custom_op_toks);
int run_monty(FILE *script_fd);
int custom_main(int custom_argc, char **custom_argv);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void custom_rotl(stack_t **custom_stack, unsigned int custom_line_number);
void custom_rotr(stack_t **custom_stack, unsigned int custom_line_number);
void custom_stack_mode(stack_t **custom_stack, unsigned int custom_line_number);
void custom_queue_mode(stack_t **custom_stack, unsigned int custom_line_number);
void clean_up_tokens(void);
void (*resolve_opcode(char *op))(stack_t**, unsigned int);


/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **custom_strtow(char *input_str, char *delimiters);
char *get_int(int n);
char *get_next_word(char *input_str, char *delimiters);
char **tokenize_input(FILE *custom_script_fd);

/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
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
