#include "main.ih"

// generate the unsorted vector according to the formula
void generateArr(size_t n, size_t a, size_t b, size_t c, std::vector<size_t> &arr)
{
	arr.reserve(n);

	arr.push_back(b);

	--n;
	for (size_t i = 0; i != n; ++i)
		arr.push_back((a * arr[i] + b) % c);
}