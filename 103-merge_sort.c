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
	int i = 0, j = 0, k = left;
	int left_size = mid - left + 1;
	int right_size = right - mid;

	printf("Merging...\n");
	while (i < left_size)
		container[i] = arr[left + i], i++;
	while (j < right_size)
		container[j + left_size] = arr[mid + 1 + j], j++;
	printf("[left]: ");
	for (i = 0; i < left_size; i++)
		printf("%d ", container[i]);
	printf("\n");
	printf("[right]: ");
	for (j = left_size; j < left_size + right_size; j++)
		printf("%d ", container[j]);
	printf("\n");
	i = 0, j = left_size;
	while (i < left_size && j < left_size + right_size)
	{
		if (container[i] <= container[j])
			arr[k] = container[i], i++;
		else
			arr[k] = container[j], j++;
		k++;
	}
	while (i < left_size)
		arr[k] = container[i], i++, k++;
	while (j < left_size + right_size)
		arr[k] = container[j], j++, k++;
	printf("[Done]: ");
	for (i = left; i <= right; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
