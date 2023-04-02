#include "sort.h"

/**
 * max_value - finds the max value in an array
 * @array: array
 * @size: size of the array
 * Return: max value of the array
 */
int max_value(int *array, size_t size)
{
	int max_value;
	size_t i;

	if (array == NULL || size == 0)
		return (0);

	max_value = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return (max_value);
}

/**
 * counting_sort - counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *tmp;
	int i, k;
	size_t j;

	if (array == NULL || size < 2)
		return;

	k = max_value(array, size) + 1;
	count = malloc(sizeof(int) * k);
	if (count == NULL)
		return;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < k; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		++count[array[j]];

	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, k);

	for (i = size - 1; i >= 0; i--)
		tmp[--count[array[i]]] = array[i];

	free(count);
	for (j = 0; j < size; j++)
		array[j] = tmp[j];

	free(tmp);
}
