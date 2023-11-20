#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sort list using insert algorithm
 * @list: the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *list1;

	if (!(*list) || !((*list)->next))
		return;
	list1 = (*list)->next;
	while (list1)
	{
		while (list1->prev && list1->prev->n > list1->n)
		{
			list1 = swapp(list1, list);
			print_list(*list);
		}
		list1 = list1->next;
	}
}



/**
 * swapp - swap 2 nodes
 * @node: the node
 * @list: the list
 * Return: new list
 */
listint_t *swapp(listint_t *node, listint_t **list)
{
	listint_t *jj = node->prev, *ii = node;

	jj->next = ii->next;
	if (ii->next)
		ii->next->prev = jj;
	ii->next = jj;
	ii->prev = jj->prev;
	jj->prev = ii;
	if (ii->prev)
		ii->prev->next = ii;
	else
		*list = ii;
	return (ii);

}
