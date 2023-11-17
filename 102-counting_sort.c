#include "sort.h"

/**
 * get_max - function to get the maximum value in an array of integers.
 * @array: pointer to int.
 * @size: size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maximum, j;

	for (maximum = array[0], j = 1; j < size; j++)
	{
		if (array[j] > maximum)
			maximum = array[j];
	}

	return (maximum);
}

/**
 * counting_sort - function to sort an array of integers in ascending order.
 * @array: pointer to int
 * @size: size of the array.
 *
 * Description: Prints the counting array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_max(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (maximum + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (maximum + 1); j++)
		count[j] += count[j - 1];
	print_array(count, maximum + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(count);
}
