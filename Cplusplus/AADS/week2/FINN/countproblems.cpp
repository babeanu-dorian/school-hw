#include "finn.h"

// output the number of problems that can be solved when starting with a given type
size_t countProblems(size_t skill, size_t curType, Heap<Challenge> const hardProb[2])
{
	Heap<Challenge> hard[2] = {hardProb[0], hardProb[1]};
	// 2 priority queues, 1 for each type,
	// sorted by skill reward (highest at the top)
	Heap<size_t> solvable[2];

	size_t problemCount = 0;
	while (true)
	{
		selectSolvable(skill, hard[curType], solvable[curType]);

		// no problems solvable of this type, return
		if (solvable[curType].empty())
			return problemCount;

		// solve the one with the highest reward
		skill += solvable[curType].top();
		solvable[curType].pop();

		// alternate problem type
		curType = 1 - curType;
		++problemCount;
	}
}
