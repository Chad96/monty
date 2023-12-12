#include <stdlib.h>

char *convert_int_to_string(int number);
unsigned int absolute_value(int value);
int calculate_required_buffer_length(unsigned int number, unsigned int base);
void fill_buffer_with_number_base(unsigned int number, unsigned int base,
		char *buffer, int buffer_size);

/**
 * convert_int_to_string - converts an integer to a string
 * @number: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *convert_int_to_string(int number)
{
	unsigned int absolute_value_number;
	int length = 0;
	long long_number = 0;
	char *result;

	absolute_value_number = absolute_value(number);
	length = calculate_required_buffer_length(absolute_value_number, 10);

	if (number < 0 || long_number < 0)
		length++; /* negative sign */
	result = malloc(length + 1); /* create new string */
	if (!result)
		return (NULL);

	fill_buffer_with_number_base(absolute_value_number, 10, result, length);
	if (number < 0 || long_number < 0)
		result[0] = '-';
	return (result);
}

/**
 * absolute_value - gets the absolute value of an integer
 * @value: integer to get absolute value of
 *
 * Return: unsigned integer absolute representation of value
 */
unsigned int absolute_value(int value)
{
	if (value < 0)
		return (-(unsigned int)value);
	return ((unsigned int)value);
}

/**
 * calculate_required_buffer_length - gets length of buffer
 * @number: number to get length needed for
 * @base: base of number representation used by buffer
 * Return: integer containing length of buffer
 */
int calculate_required_buffer_length(unsigned int number, unsigned int base)
{
	int length = 1;

	while (number > base - 1)
	{
		length++;
		number /= base;
	}
	return (length);
}

/**
 * fill_buffer_with_number_base - fills buffer with numbers
 * @number: number to convert to string
 * @base: base of number used in conversion
 * @buffer: buffer to fill with result of conversion
 * @buffer_size: size of buffer in bytes
 * Return: always void.
 */
void fill_buffer_with_number_base(unsigned int number, unsigned int base,
		char *buffer, int buffer_size);
{
	int remainder, i = buffer_size - 1;

	buffer[buffer_size] = '\0';
	while (i >= 0)
	{
		remainder = number % base;
		if (remainder > 9) /* return lowercase ascii val representation */
			buffer[i] = remainder + 87; /* 10 will be a, 11 = b, ... */
		else
			buffer[i] = remainder + '0';
		number /= base;
		i--;
	}
}
