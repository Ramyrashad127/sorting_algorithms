#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sort array using selection sort algorithm
 * @array: the array
 * @size: size of array
 * return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, t;
	int curr;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		curr = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < curr)
			{
				curr = array[j];
				t = j;
			}
		}
		curr = array[t];
		array[t] = array[i];
		array[i] = curr;
		print_array(array, size);
	}
}
