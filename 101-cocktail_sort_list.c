#include "sort.h"
/**
 * cocktail_sort_list - function that sorts the list as requested
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *head, *len;
	int i = 0, j = 0, swaped = 1;

	if (!list || !*list)
		return;
	len = *list;
	for (i = 0; len; i++)
	{
		len = len->next;
	}
	if (i < 2)
		return;
	head = *list;
	while (j < i)
	{
		swaped = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap_listint(head, head->next);
				swaped++;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = tail_traverse(head, tail, *list);
		*list = head;
		j++;
	}
}
/**
 * swap_listint - function of swap
 * @a: first intiger to be swapped
 * @b: second intiger to be swapped
 */
void swap_listint(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
/**
 * tail_traverse - traversing the list dow to the tail
 * @head: head of the list
 * @tail: tail of the list
 * @list: list to be checked
 * Return: index of the tail
 */
listint_t *tail_traverse(listint_t *head, listint_t *tail, listint_t *list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_listint(tail->prev, tail);
			if (tail->prev == NULL)
				list = tail;
			print_list(list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}
