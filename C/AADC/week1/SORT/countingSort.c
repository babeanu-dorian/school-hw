#include "main.ih"

void countingSort(size_t *arr, size_t size, size_t upBound)
{
	size_t *hist = safeMalloc(upBound * sizeof(size_t));

	for (size_t i = 0; i != upBound; ++i)
		hist[i] = 0;

	// count the number of instances for each element
	for (size_t i = 0; i != size; ++i)
		++hist[arr[i]];

	// reconstruct the array using the histogram
	size_t outIdx = 0;
	for (size_t i = 0; i != upBound; ++i)
	{
		for(; hist[i]--;)
			arr[outIdx++] = i;
	}

	free(hist);
}