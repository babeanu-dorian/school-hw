/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		27-02-2017
 * Challenge:	JAKE
 * 
 * Program description:
 * 
 * This program reads a number n followed by n positive integers between 1
 * and 100. The program will then output the most balanced pair of sums of
 * 2 partitions including all the n input numbers while not including common
 * ones (common in index, not in value), sorted in increasing order.
 *  
 * Complexity analysis:
 * 
 * Time complexity: Computing the sum is O(n), computing the first balanced sum
 * is O(n * sum). So, the total time complexity is O(n + n * sum) = O(n * sum),
 * where n is the size of the array and sum is the sum of all elements.
 * 
 * Memory complexity: The only data structures dependent of input size are
 * the array of size n and the matrix of size n * sum. So, the total space
 * complexity is O(n + n * sum) = O(n * sum), where n is the size of the
 * array and sum is the sum of all elements.
 */

#include "jake.ih"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n;
	std::cin >> n;

	std::vector<size_t> arr(n);
	size_t sum = 0;

	// read input and compute sum
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		std::cin >> *it;
		sum += *it;
	}

	size_t first = balancedPartSum(arr, sum);

	// second == sum - first
	std::cout << first << ' ' << (sum - first) << std::endl;
}
