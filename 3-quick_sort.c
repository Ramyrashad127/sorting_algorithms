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
void quick(int *array, int low, int high, int size)
{
	int pivot = high;

	if (low < high)
	{
		pivot = part(array, low, high, size);
		quick(array, low, pivot - 1, size);
		quick(array, pivot + 1, high, size);
	}
}
/**
 * swap - swap
 * @array: array
 * @i: index
 * @j: index
 */
void swap(int *array, int i, int j)
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
int part(int *array, int low, int high, int size)
{
	int i = low, j = high, pivot = high;

	while (1)
	{
		while (array[i] <= array[pivot] && i != pivot)
			i = i + 1;
		if (pivot == i)
			break;
		else if (array[pivot] < array[i])
		{
			swap(array, pivot, i);
			print_array(array, size);
			pivot = i;
		}
		while (array[j] >= array[pivot] && j != pivot)
			j = j - 1;
		if (pivot == j)
			break;
		else if (array[pivot] > array[j])
		{
			swap(array, pivot, j);
			print_array(array, size);
			pivot = j;
		}
	}
	return (pivot);
}
