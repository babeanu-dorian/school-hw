#include "main.ih"

void jumpPrint(size_t *arr, size_t size, size_t jump)
{
	for (size_t i = 0; i < size; i += jump)
		printf("%zu ", arr[i]);
	putchar('\n');
}