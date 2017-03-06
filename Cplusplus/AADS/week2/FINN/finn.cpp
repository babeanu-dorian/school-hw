/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		27-02-2017
 * Challenge:	FINN
 * 
 * Program description:
 * 
 * This program reads two numbers n and h, followed by n grups of 3 integers,
 * t (the type of the problem), d (the difficulty of the problem) and s (the
 * skill increase for solving the problem). The input number h represents the
 * initial skill of the problem solver. The program will output the maximum
 * number of problems that can be solved without consecutively solving two
 * problems of the same type.
 *  
 * Complexity analysis:
 * 
 * Time complexity: In the worst case scenario, each one of the n challenges is
 * pushed into one of the difficulty sorted heaps, then poped, then pushed into
 * one of the skill reward sorted heaps, then poped again. Since the complexities
 * of pop and push for std::priority_queue areboth log(size), where size is the
 * number of elements in the heap (worst case n for this program) and the
 * complexity of top is O(1), the total time complexity is O(n * (log(n) + 1)) =
 * = O(n * log(n))
 * 
 * Memory complexity: The only data structures dependent of input size are
 * the 6 heaps:
 * - 2 difficulty sorted ones, 1 for each type, their total size is n
 * - 2 copies of the difficulty sorted heaps, their total size is n
 * - 2 skill reward sorted heaps, their total size is n
 * The resulted space complexity is O(3 * n) = O(n)
 */

#include "finn.h"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n, skill;
	std::cin >> n >> skill;

	size_t t, d, s;
	// 2 priority queues, 1 for each type,
	// sorted by difficulty (lowest at the top)
	Heap<Challenge> hard[2];
	for (size_t i = 0; i != n; ++i)
	{
		std::cin >> t >> d >> s;
		Challenge ch(d, s);
		if (t)
			hard[1].push(ch);
		else
			hard[0].push(ch);
	}

	size_t maxProblemCount = 0;

	// try both types as the starting one, get the max one
	for (size_t curType = 0; curType != 2; ++curType)
	{
		size_t problemCount = countProblems(skill, curType, hard);
		if (problemCount > maxProblemCount)
			maxProblemCount = problemCount;
	}

	std::cout << maxProblemCount << std::endl;
}
