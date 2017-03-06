/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		27-02-2017
 * Challenge:	BMO
 * 
 * Program description:
 * 
 * This program reads a number n followed by an n by n matrix of 0's and 1's.
 * It then outputs for every integer m in [1, n] the nuber of m by m partitions
 * of the original matrix that ony contain 1's.
 *  
 * Complexity analysis:
 * 
 * Time complexity: Computing the histogram from the matrix is O(n^2), since
 * the program has to go over every element in the n by n matrix. Finalizing
 * the histogram (adding each element to the one before it) is linear in the
 * size of the histogram, so O(n). Final time complexity: O(n^2 + n) = O(n^2),
 * where n is the first integer read from input.
 * 
 * Memory complexity: The only data structures dependent of input size are
 * the 3 vectors used for storing the previous line, the current line and
 * the histogram. Their respective sizes are n + 1, n + 1 and n. The resulting
 * space complexity is O(n + 1 + n + 1 + n) = O(3n + 2) = O(n), where n is the
 * first integer read from input.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n;
	std::cin >> n;

	std::vector<size_t> countSq(n, 0);

	// dimension after padding the matrix with 0s, on the left and top:
	++n;
	std::vector<size_t> prevLine(n, 0);

	// read and process input
	for (size_t y = 1; y != n; ++y)
	{
		std::vector<size_t> curLine(n, 0);

		for (size_t x = 1; x != n; ++x)
		{
			size_t sqVal;
			std::cin >> sqVal;
			if (sqVal)
			{
				// count the size of the sqare of 1's and store it in the bottom-left location
				sqVal = std::min({curLine[x - 1], prevLine[x], prevLine[x - 1]});
				++countSq[sqVal]; // count the instances of each number
				curLine[x] = 1 + sqVal;
			}
		}

		// the current line becomes the previous line for the next line
		prevLine = std::move(curLine);
	}

	// produce the count for each size, not just for each number
	for (size_t i = n - 2; i--;)
		countSq[i] += countSq[i + 1];

	// write output
	std::copy(countSq.begin(), countSq.end(),
			  std::ostream_iterator<size_t>(std::cout, "\n"));
}
