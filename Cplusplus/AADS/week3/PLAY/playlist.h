#ifndef INCLUDED_PLAYLIST_
#define INCLUDED_PLAYLIST_

#include <unordered_set>

struct hashFunctor
{
	size_t operator()(size_t x) const
	{
		return x;
	}
};

// this function returns 0 if the value was not found and 1 if it was
// and removes the value from the set if it was found
template <typename T, typename Hash>
size_t countAndErase(T const &key, std::unordered_set<T, Hash> &uSet)
{
	auto it = uSet.find(key);
	if (it == uSet.end())
		return 0;
	uSet.erase(it);
	return 1;
}

#endif