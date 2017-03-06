/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		27-02-2017
 * Challenge:	MAP
 * 
 * Program description:
 * 
 * This program reads two positive integers n and m, representing the hight
 * and width of an input matrix. The program then reads a matrix of n by m
 * characters and computes the minimum width of a partition of the original
 * matrix, such that the original matrix is composed of 2 horizontally
 * overlapping identical partitions.
 *  
 * Complexity analysis:
 * 
 * Time complexity: Initializing the histogram is in O(m), where m is the
 * number of columns in the matrix. For every column in the entered matrix,
 * computing the column takes n steps (n = number of rows), inserting it
 * in a set takes on average O(1) (std::hash<std::string> takes O(1) in the
 * length of the string), and updating the histogram is O(1). Searching
 * the histogram for the maximum shift takes O(m) and using it to compute
 * the width of the partition take O(1). In total, the time complexity is
 * O(m + m * (n + 1 + 1) + m + 1) = O(m * (n + 4)) = O(m * n).
 * 
 * Memory complexity: The input matrix requires n * m memory and the histogram
 * and the set are linear in m. Therefore the space complexity is
 * O(n * m + m + m) = O(n * m).
 */

#include "map.ih"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n, m;

	std::cin >> n >> m;
	std::vector<std::string> overlapMap;
	for (size_t i = 0; i != n; ++i)
	{
		std::string row;
		std::cin >> row;
		overlapMap.push_back(row);
	}

	std::cout << m - maxShift(overlapMap) << std::endl;
}