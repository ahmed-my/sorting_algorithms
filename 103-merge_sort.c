#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - function to sort a sub array of integers.
 * @subarr: sub array of an array of integers to sort.
 * @buff: pointer buffer to store the sorted sub array.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - function merge sort algorithm through recursion.
 * @subarr: pointer sub array of an array of integers to sort.
 * @buff: buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - function to sort an array of integers in ascending
 * @array: pointer array of integers.
 * @size: size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
