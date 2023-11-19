#include "sort.h"
/**
 * quick_sort - sort algorithm
 * @array: arr
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quick(array, 0, size - 1);
}

/**
 * quick - quick sort
 * @array: array
 * @low: low
 * @high: high
 */
void quick(int *array, size_t low, size_t high)
{
	int pivot;
	if (low < high)
	{
		pivot = part(array, low, high);
		quick(array, low, pivot - 1);
		quick(array, pivot + 1, high);
	}
}
/**
 * swap - swap
 * @array: array
 * @i: index
 * @j: index
 */
void swap(int *array, size_t i, size_t j)
{
	int k = array[i];
	array[i] = array[j];
	array[j] = k;
}
/**
 * part - parti
 * @array: array of int
 * @low: low
 * @high: high
 * Retuen: index
 */
size_t part(int *array, size_t low, size_t high)
{
	size_t i = low, j = high, pivot = high;
	while (1)
	{
		while (array[i] <= array[pivot] && i != pivot)
			i++;
		if (pivot == i)
			break;
		else
		{
			swap(array, pivot, i);
			pivot = i;
		}
		while (array[j] >= array[pivot] && j != pivot)
			j--;
		if (pivot == j)
			break;
		else
		{
			swap(array, pivot, j);
			pivot = j;
		}
	}
	return pivot;
}
