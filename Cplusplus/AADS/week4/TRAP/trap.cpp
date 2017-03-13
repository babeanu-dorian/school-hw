/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		12-03-2017
 * Challenge:	Trapezium
 * 
 * Program description:
 * 
 * This program reads a positive integer n, followed by n pairs of positive
 * integers x and y, representing the coordinates of n points. The program
 * then computes and displays the number of trapeziums (quadrilaterals with
 * at least two parallel sides) that can be formed with those n points.
 * Parallelograms are counted twice.
 *  
 * Complexity analysis:
 * 
 * Time complexity: Generating the slopes is done in O(n(n - 1) / 2) = O(n^2).
 * Inserting a key or modiying its corresponding value into std::unordered_map
 * have an average complexity of O(1). So mapping each slope to its count is
 * O(n^2 * 1) = O(n^2). Iterating over the elements of the map to computing the
 * count of trapeziums is O(n(n - 1) / 2) = O(n^2). The overall time complexity
 * is O(n^2 + n^2) = O(n^2).
 * 
 * Memory complexity: The vector used for storing the points increases linearly
 * with n and the unordered_map increases linearly with the number of slopes,
 * which is n(n - 1) / 2. Therefore, the total space complexity is
 * O(n + n(n - 1) / 2) = O(n^2).
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cmath>
#include <utility>

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n;
	std::cin >> n;

	// read points
	std::vector< std::pair<double, double> > points(n);
	for (size_t i = 0; i != n; ++i)
		std::cin >> points[i].first >> points[i].second;

	// compute slopes and map them to their counts
	std::unordered_map<double, size_t> slopes;
	for (auto pointA = points.begin(); pointA != points.end(); ++pointA)
	{
		for (auto pointB = pointA + 1; pointB!= points.end(); ++pointB)
		{
			double xDiff = pointB->first - pointA->first;
			if (xDiff)
				++slopes[(pointB->second - pointA->second) / xDiff];
			else // (x / 0) will be treated as the maximum value of double
				++slopes[std::numeric_limits<double>::max()];
		}
	}

	size_t trapCount = 0;

	// count trapeziums
	for (auto it = slopes.begin(); it != slopes.end(); ++it)
	{
		// n parallel lines produce n * (n - 1) / 2 trapeziums
		trapCount += it->second * (it->second - 1) / 2;
	}

	std::cout << trapCount << std::endl;
}