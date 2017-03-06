#include "map.ih"

// this function computes the maximum shift for which
// the 2nd partition overlays the 1st
size_t maxShift(std::vector<std::string> const &overlapMap)
{
	size_t width = overlapMap.front().size();
	// histogram of shifts (distances between first occurence
	// in partition 1 and first occurence in possible partition 2)
	std::vector<size_t> shiftHist(width / 2 + width % 2, 0);
	// maps each column to the position at which it was first encountered
	std::unordered_map<std::string, size_t> colIdxMap;
	size_t uniqueCols = 0; // number of unique columns
	for (size_t i = 0; i != width; ++i)
	{
		std::string col; // column of index i
		for (size_t j = 0; j != overlapMap.size(); ++j)
			col.push_back(overlapMap[j][i]);

		// if insertion succeeded, i is the first index of this matrix
		if (colIdxMap.insert(std::make_pair(col, i)).second)
			++uniqueCols;

		// measure shift (distance between first encounter and current encounter)
		size_t shift = i - colIdxMap[col];
		if (shift < shiftHist.size())
			++shiftHist[shift];
	}

	// find the greatest shift by going from end to beginning
	for (size_t i = shiftHist.size(); i--;)
	{
		// the shift must be allowed by all unique columns
		if (shiftHist[i] == uniqueCols)
			return i;
	}

	return 0; // this will never happen
}