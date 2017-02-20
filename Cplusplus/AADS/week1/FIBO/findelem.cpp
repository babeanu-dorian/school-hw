#include "sequence.h"

// returns the index of the element in d_seq that contains charIdx
// and modifies the passed parameter to the index of the character
// inside the element, instead of the whole sequence
size_t Sequence::findElem(size_t &charIdx)
{
	// search in existing sequence
	for (auto it = d_seq.begin(); it != d_seq.end(); ++it)
	{
		if (charIdx < *it)
			return std::distance(d_seq.begin(), it);
		charIdx -= *it;
	}

	// not found in existing sequence, compute more elements
	size_t lastIdx = d_seq.size() - 1;
	while (true)
	{
		d_seq.push_back(d_seq[lastIdx - 1] + d_seq[lastIdx]);
		++lastIdx;
		if (charIdx < d_seq.back())
			return lastIdx;
		charIdx -= d_seq.back();
	}
}