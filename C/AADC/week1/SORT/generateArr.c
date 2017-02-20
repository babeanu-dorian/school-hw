#include "main.ih"

// generate the unsorted array according to the formula
size_t *generateArr(size_t n, size_t a, size_t b, size_t c)
{
	size_t *arr = safeMalloc(n * sizeof(size_t));

	arr[0] = b;
	for (size_t i = 1; i != n; ++i)
		arr[i] = (a * arr[i - 1] + b) % c;

	return arr;
}