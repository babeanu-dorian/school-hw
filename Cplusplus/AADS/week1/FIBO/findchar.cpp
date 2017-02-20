#include "sequence.h"

// finds the character with index charIdx in the element with index elIdx
// (an element is the concatenation of the previous two elements,
// used to form the sequence)
char Sequence::findChar(size_t elIdx, size_t charIdx)
{
	if (elIdx == 0)
		return d_A1[charIdx];

	if (elIdx == 1)
		return d_A2[charIdx];

	// seq[elIdx] = seq[elIdx-2] + seq[elIdx - 1],
	// find which one of the two contains charIdx
	// and go into recursion with it
	elIdx -= 2;
	if (charIdx >= d_seq[elIdx])
		return findChar(elIdx + 1, charIdx - d_seq[elIdx]);

	return findChar(elIdx, charIdx);
}