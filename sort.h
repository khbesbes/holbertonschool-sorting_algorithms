#ifndef _SORT_H_
#define _SORT_H_
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b); 
size_t partition(int array[], size_t size);
void print_sort(int array[], size_t size, int init);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_listint(listint_t *a, listint_t *b);
listint_t *tail_traverse(listint_t *head, listint_t *tail, listint_t *list);
int max_value(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort_recursion(int *array, size_t left, size_t right, int *tmp);
void merge_sorted_a(int *array, size_t low, size_t mid, size_t high, int *tmp);
void merge_sort(int *array, size_t size);

#endif

