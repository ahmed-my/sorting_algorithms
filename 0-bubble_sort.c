#include "sort.h"

/**
 * swap_ints - function to swap two integers in an array.
 * @m: pointer to int. first integer.
 * @n: pointer to int. second integer.
 */
void swap_ints(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: pointer to int
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
