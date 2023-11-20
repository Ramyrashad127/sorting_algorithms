#ifndef sort_file
#define sort_file
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
int part(int *array, int low, int high, int size);
void swap(int *array, int i, int j);
void quick(int *array, int low, int high, int size);
void quick_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);

void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *swapp(listint_t *node, listint_t **list);
#endif
