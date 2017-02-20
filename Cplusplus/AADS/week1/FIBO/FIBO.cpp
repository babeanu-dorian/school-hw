/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		18-02-2017
 * Challenge:	Potion
 * 
 * Program description:
 * 
 * This program reads two strings A[1] and A[2], a positive integer m and m positive
 * integers representing indices of characters in the following infinite sequence:
 * A[n] = A[n-2]A[n-1]
 * For every index inputed, the program outputs the character at that index.
 *  
 * Complexity analysis:
 * 
 * Time complexity: Since the numbers in a fibonacci-like sequence grow
 * exponentially (in base 2) and the algorithm traverses the sequence linearly for
 * each index in search for the smallest number greater or equal to the index, the
 * complexity for one index is O(log(i)), where i is the index. Therefore, the time
 * complexity for all m indices is O(sum of log(idx[k]), with k from 1 to m) =
 * = O(log(product of idx[k], with k from 1 to m))
 * 
 * Memory complexity: Since the program only generates sequence elements when needed
 * and the numbers in a fibonacci-like sequence grow exponentially (in base 2), the
 * space complexity is O(log(maxIdx)), where maxIdx is the maximum of all m inides.
 */

#include <iostream>

#include "sequence.h"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t m;
	std::string A1;
	std::string A2;
	
	std::cin >> A1 >> A2 >> m;
	
	Sequence sq(A1, A2);
	
	size_t idx;
	for (size_t i = 0; i != m; ++i)
	{
		std::cin >> idx;
		std::cout << sq[idx];
	}
	
	std::cout << std::endl;
}