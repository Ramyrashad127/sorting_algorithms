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
	quick(array, 0, size - 1, size);
}

/**
 * quick - quick sort
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 */
void quick(int *array, size_t low, size_t high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = part(array, low, high, size_t size);
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
 * @size: size
 * Return: index
 */
size_t part(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low, j = high, pivot = high;

	while (1)
	{
		while (array[i] <= array[pivot] && i != pivot)
			i++;
		if (pivot == i)
			break;
		swap(array, pivot, i);
		print_array(array, size);
		pivot = i;
		while (array[j] >= array[pivot] && j != pivot)
			j--;
		if (pivot == j)
			break;
		swap(array, pivot, j);
		print_array(array, size);
		pivot = j;
	}
	return (pivot);
}
