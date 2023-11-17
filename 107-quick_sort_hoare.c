#include "sort.h"

void swap_ints(int *m, int *n);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

/**
 * hoare_partition - subset of an array of integers
 * @array: pointer array of integers.
 * @size: size of the array.
 * @left: start index of the subset to order.
 * @right: end index of the subset to order.
 *
 * Return: partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - function to implement the quicksort algorithm
 * @array: pointer array of integers to sort.
 * @size: size of the array.
 * @left: start index of the array partition to order.
 * @right: end index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partition - 1);
		hoare_sort(array, size, partition, right);
	}
}

/**
 * quick_sort_hoare - function to sort an array of integers
 * @array: pointer array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
