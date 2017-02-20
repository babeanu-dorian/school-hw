#include "main.ih"

void *safeMalloc(size_t size)
{
	void *arr = malloc(size);
	assert(arr);
	return arr;
}