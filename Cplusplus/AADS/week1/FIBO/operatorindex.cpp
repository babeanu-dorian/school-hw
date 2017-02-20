#include "sequence.h"

char Sequence::operator[](size_t charIdx)
{
	size_t elIdx = findElem(--charIdx);
	return findChar(elIdx, charIdx);
}