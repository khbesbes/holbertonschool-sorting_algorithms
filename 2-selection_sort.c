#include "sort.h"
/**
* selection_sort - selecte the sort of algorithm
* @array: pointer to array.
* @size: type of sturct.
* return : 0
*/
void selection_sort(int *array, size_t size)
{
unsigned int i, j, min_x;
if (!array)
return;
for (i = 0; i < size - 1; i++)
{
min_x = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_x])
min_x = j;

}
if (min_x != i)
{
swap(&array[min_x], &array[i]);
print_array(array, size);
}
}
}
/**
* swap - function swap entre value.
* @a: first value
* @b: second value
* return : 0
*/
void swap(int *a, int *b)
{
int tmp;
tmp = *b;
*b = *a;
*a = tmp;
}


