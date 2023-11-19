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
	size_t i, j;
	int curr;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				curr = array[j];
				array[j] = array[i];
				array[i] = curr;
			}
		}
		print_array(array, size);
	}
}
