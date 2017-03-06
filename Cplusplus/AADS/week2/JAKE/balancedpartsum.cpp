#include "jake.ih"

// uses a matrix of n by sum to compute the partial sums of the vector,
// returns the one closest to and smaller than sum/2 (for maximum balance)
size_t balancedPartSum(std::vector<size_t> arr, size_t sum)
{
	size_t n = arr.size() + 1;
	sum = sum / 2 + 1; // no need to go all the way to sum

	// matrix filled with false
	// vector<bool> too slow, used vector<char> instead
	std::vector< std::vector<char> > subsetSums(n, std::vector<char>(sum, 0));

	// 0 is part of all the sums
	for (auto it = subsetSums.begin(); it != subsetSums.end(); ++it)
		it->front() = true;

	// subsetSums[y][x] is true iff y can be in a partition of sum x
	for (size_t y = 1; y != n; ++y)
	{
		size_t up = y - 1;
		for (size_t x = 1; x != sum; ++x)
		{
			subsetSums[y][x] = subsetSums[up][x] ||
							    (arr[up] <= x && subsetSums[up][x - arr[up]]);
		}
	}

	//fund the one closest to and smaller than sum/2
	for (auto it = subsetSums.back().rbegin(); it != subsetSums.back().rend(); ++it)
	{
		if (*it)
			return std::distance(it, subsetSums.back().rend()) - 1;
	}

	return 0;
}
