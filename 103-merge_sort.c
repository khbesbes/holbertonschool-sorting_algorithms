#include "sort.h"

/**
 * merge_sort_recursion - splits and sorts array
 * @array: array to be sorted
 * @left: first index of the array
 * @right: last index of the array
 * @tmp: temporary array for sorting array
 */
void merge_sort_recursion(int *array, size_t left, size_t right, int *tmp)
{
	size_t mid;

	if (array == NULL || tmp == NULL || right <= (left + 1))
		return;

	mid = (left + right) / 2;

	merge_sort_recursion(array, left, mid, tmp);
	merge_sort_recursion(array, mid, right, tmp);

	merge_sorted_a(array, left, mid, right, tmp);
}

/**
 * merge_sorted_a - merges sorted arrays
 * @array: array
 * @low: first index
 * @mid: mid of the array
 * @high: last index
 * @tmp: temporary array
 */
void merge_sorted_a(int *array, size_t low, size_t mid, size_t high, int *tmp)
{
	size_t i;
	size_t left;
	size_t right;

	printf("Merging...\n");
	printf("[left]: ");
	print(array, low, mid);

	printf("[right]: ");
	print(array, mid, high);

	for (left = low; left < high; ++left)
		tmp[left] = array[left];

	left = low;
	right = mid;

	for (i = low; i < high; ++i)
	{
		if (left >= mid)
			array[i] = tmp[right++];
		else if (right >= high)
			array[i] = tmp[left++];
		else if (tmp[left] <= tmp[right])
			array[i] = tmp[left++];
		else
			array[i] = tmp[right++];
	}

	printf("[Done]: ");
	print(array, low, high);
}

/**
 * print - print part of array
 * @array: array
 * @low: first index
 * @high: last index
 */
void print(int *array, size_t low, size_t high)
{
	size_t i;

	i = low;
	while (array && i < (high - 1))
		printf("%d, ", array[i++]);
	printf("%d\n", array[i]);
}

/**
 * merge_sort - merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	merge_sort_recursion(array, 0, size, tmp);

	free(tmp);
}