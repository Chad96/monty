#include <stdlib.h>
#include "monty.h"

char **custom_strtow(char *input_str, char *delimiters);
int is_delimiter(char character, char *delimiters);
int get_word_length(char *input_str, char *delimiters);
int get_word_count(char *input_str, char *delimiters);
char *get_next_word(char *input_str, char *delimiters);

/**
 * custom_strtow - takes a string and separates its words
 *
 * @input_str: string to separate into words
 * @delimiters: delimiters to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */
char **custom_strtow(char *input_str, char *delimiters)
{
	char **word_array = NULL;
	int word_count, word_length, n, i = 0;

	if (input_str == NULL || !*input_str)
		return (NULL);
	word_count = get_word_count(input_str, delimiters);

	if (word_count == 0)
		return (NULL);
	word_array = malloc((word_count + 1) * sizeof(char *));

	if (word_array == NULL)
		return (NULL);
	while (i < word_count)
	{
		word_length = get_word_length(input_str, delimiters);
		if (is_delimiter(*input_str, delimiters))
		{
			input_str = get_next_word(input_str, delimiters);
		}
		word_array[i] = malloc((word_length + 1) * sizeof(char));
		if (word_array[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(word_array[i]);
			}
			free(word_array);
			return (NULL);
		}
		n = 0;
		while (n < word_length)
		{
			word_array[i][n] = *(input_str + n);
			n++
		}
		word_array[i][n] = '\0'; /* set end of str */
		input_str = get_next_word(input_str, delimiters);
		i++;
	}
	word_array[i] = NULL; /* last element is null for iteration */
	return (word_array);
}

/**
 * is_delimiter - checks if stream has delimiter char
 *
 * @ch: character in stream
 * @delimiters: Pointer to null-terminated array of delimiters
 *
 * Return: 1 (success) 0 (failure)
 */
int is_delimiter(char ch, char *delimiters)
{
	int j = 0;

	while (delimiters[j])
	{
		if (delimiters[j] == ch)
			return (1);
		j++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @input_str: string to get word length from current word
 * @delimiters: delimiters to use to delimit words
 *
 * Return: word length of the current word
 */
int get_word_length(char *input_str, char *delimiters)
{
	int word_length = 0, pending = 1, i = 0;

	while (*(input_str + i))
	{
		if (is_delimiter(input_str[i], delimiters))
			pending = 1;
		else if (pending)
		{
			word_length++;
		}
		if (word_length > 0 && is_delimiter(input_str[i], delimiters))
			break;
		i++;
	}
	return (word_length);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @input_str: string to get word count from
 * @delimiters: delimiters to use to delimit words
 *
 * Return: the word count of the string
 */
int get_word_count(char *input_str, char *delimiters)
{
	int word_count = 0, pending = 1, i = 0;

	while (*(input_str + i))
	{
		if (is_delimiter(input_str[i], delimiters))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @input_str: string to get the next word from
 * @delimiters: delimiters to use to delimit words
 *
 * Return: pointer to the first character of the next word
 */
char *get_next_word(char *input_str, char *delimiters)
{
	int pending = 0;
	int i = 0;

	while (*(input_str + i))
	{
		if (is_delimiter(input_str[i], delimiters))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (input_str + i);
}
