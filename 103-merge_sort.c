#include "sort.h"
/**
 * merge_sort - merge
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *container = malloc(sizeof(int) * size);

	if (!array || !size)
		return;
	merge_recursive(array, container, 0, size - 1);
	free(container);

}
/**
 * merge_recursive - function rec
 * @arr: array
 * @container: contain
 * @left: left
 * @right: right
 */
void merge_recursive(int *arr, int *container, int left, int right)
{
	int mid;

	if (left < right)
	{
		if ((left + right) % 2 != 0)
			mid = ((left + right) / 2);
		else
			mid = (left + right) / 2 - 1;
		merge_recursive(arr, container, left, mid);
		merge_recursive(arr, container, mid + 1, right);
		merge(arr, container, left, mid, right);
		printf("\n");
	}
}
/**
 * merge - merge
 * @arr: array
 * @container: con
 * @left: left
 * @mid: mid
 * @right: right
 */
void merge(int *arr, int *container, int left, int mid, int right)
{
	int i = 0, j = 0, k = left, l_size = mid - left + 1, right_size = right - mid;

	printf("Merging...\n");
	while (i < l_size)
		container[i] = arr[left + i], i++;
	while (j < right_size)
		container[j + l_size] = arr[mid + 1 + j], j++;
	printf("[left]: ");
	for (i = 0; i < l_size; i++)
	{
		printf("%d", container[i]);
		if (i != l_size - 1)
			printf(", ");
	}
	printf("\n"), printf("[right]: ");
	for (j = l_size; j < l_size + right_size; j++)
	{
		printf("%d", container[j]);
		if (j != l_size + right_size - 1)
			printf(", ");
	}
	printf("\n"), i = 0, j = l_size;
	while (i < l_size && j < l_size + right_size)
	{
		if (container[i] <= container[j])
			arr[k] = container[i], i++, k++;
		else
			arr[k] = container[j], j++, k++;
	}
	while (i < l_size)
		arr[k] = container[i], i++, k++;
	while (j < l_size + right_size)
		arr[k] = container[j], j++, k++;
	printf("[Done]: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", arr[i]);
		if (i != right)
			printf(", ");
	}
}
