#include "main.ih"

void countingSort(std::vector<size_t> &arr, size_t upBound)
{
	std::vector<size_t> hist(upBound, 0);

	// count the number of instances for each element
	for (auto it = arr.begin(); it != arr.end(); ++it)
		++hist[*it];

	// reconstruct the array using the histogram
	auto outIt = arr.begin();
	for (size_t i = 0; i < upBound; ++i)
	{
		for(; hist[i]--; ++outIt)
			*outIt = i;
	}
}