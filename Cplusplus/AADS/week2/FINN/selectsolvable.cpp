#include "finn.h"

// move the solvable problems from the hard heap to the solvable heap
void selectSolvable(size_t skill, Heap<Challenge> &hard, Heap<size_t> &solvable)
{
	while (hard.size() && hard.top().d_diff <= skill)
	{
		solvable.push(hard.top().d_skill);
		hard.pop();
	}
}
