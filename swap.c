#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
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
*a =tmp;
}
