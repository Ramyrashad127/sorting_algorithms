#include "sort.h"
/**
 * bubble_sort - simple
 * @array: arrat
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, curr;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				curr = array[j];
				array[j] = array[j + 1];
				array[j + 1] = curr;
				print_array(array, size);
			}
		}
	}
}
