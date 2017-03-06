#ifndef INCLUDED_FINN_
#define INCLUDED_FINN_

#include <iostream>
#include <queue>

template <typename T>
using Heap = std::priority_queue<T>;

struct Challenge
{
	size_t d_diff;
	size_t d_skill;

	public:
		Challenge(size_t difficulty, size_t skill)
		:
			d_diff(difficulty),
			d_skill(skill)
		{}
};

// ordering to keep the lowest difficulty at the top in a priority queue
inline bool operator <(Challenge const &rhs, Challenge const &lhs)
{
	return rhs.d_diff > lhs.d_diff;
}

size_t countProblems(size_t skill, size_t curType, Heap<Challenge> const hardProb[2]);
void selectSolvable(size_t skill, Heap<Challenge> &hard, Heap<size_t> &solvable);

#endif
