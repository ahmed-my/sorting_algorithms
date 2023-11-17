#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - function to get the maximum value in an array of integers.
 * @array: pointer array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum, k;

	for (maximum = array[0], k = 1; k < size; k++)
	{
		if (array[k] > maximum)
			maximum = array[k];
	}

	return (maximum);
}

/**
 * radix_counting_sort - function to sort the significant digits of integer
 * @array: pointer array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort on.
 * @buff: pointer buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t j;

	for (j = 0; j < size; j++)
		count[(array[j] / sig) % 10] += 1;

	for (j = 0; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		buff[count[(array[j] / sig) % 10] - 1] = array[j];
		count[(array[j] / sig) % 10] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = buff[j];
}

/**
 * radix_sort - function to sort integers array in ascending order
 * @array: pointer array of integers.
 * @size: size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maximum = get_max(array, size);
	for (sig = 1; maximum / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
