/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		18-02-2017
 * Challenge:	Fractal
 * 
 * Program description:
 * 
 * This program reads an integer t corresponding to the number of following input
 * lines. It then reads t lines containing 3 integers, k (representing the order
 * of the Hilbert Curve) and x and y (the coordinates of a point on the 2^k by 2^k
 * matrix with origin in (1,1), the top-left corner). For each line of input,
 * the program outputs the number of edges on the Hilbert Curve between the origin
 * and the (x, y) point.
 *  
 * Complexity analysis:
 * 
 * Time complexity: The program recursively iterates over the k orders of the
 * Hilbert Curve, decreasing k by 1 every iteration. Therefore, the complexity
 * for one input line is O(k) and the total complexity is O(sumk), where sumk is
 * the sum of all k's in the t lines of input.
 * 
 * Memory complexity: The only data structure with a size dependent on the input is
 * the recursive stack, which grows linerly with k. Therefore, the space complexity
 * is O(maxk), where maxk is the breatest value of k in all t input lines.
 */

#include "main.ih"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t t, k, x, y;

	std::cin >> t;

	for(; t--;)
	{
		std::cin >> k >> x >> y;
		std::cout << hilbertDist(k, 1 << (k - 1), x - 1, y - 1) << std::endl;
	}
}