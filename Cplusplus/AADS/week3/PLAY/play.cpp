/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		06-03-2017
 * Challenge:	Playlist
 * 
 * Program description:
 * 
 * This program reads 7 positive integers n, m, a, b, c, d and e,
 * from standard input. It then reads n more positive integers and computes
 * the cardinality of the intersection between these n values and the m
 * values generated after the rule:
 * s[0] = a, s[1] = b, s[i] = c * s[i - 1] + d * s[i - 2].
 *  
 * Complexity analysis:
 * 
 * Time complexity: Inserting a value into std::unordered_set is O(1) on average,
 * so inserting n values is O(n). Finding and erasing are both O(1) on average,
 * so finding and erasing m values is O(2 * m) = O(m). Therefore the total time
 * complexity is O(n + m).
 * 
 * Memory complexity: The only data strucure with input dependent size is the
 * unordered_set, which should grow linearly with the number of inserted
 * elements. Therefore the total space complexity is O(n).
 */

#include <iostream>

#include "playlist.h"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n, m, a, b, c, d, e;

	std::cin >> n >> m >> a >> b >> c >> d >> e;

	// defauld hashing was too slow, used custom one
	std::unordered_set<size_t, hashFunctor> songRequests;

	for (size_t i = 0; i != n; ++i)
	{
		size_t sReq;
		std::cin >> sReq;
		songRequests.insert(sReq);
	}

	// number of songs requested which are in the playlist
	size_t sCount = countAndErase(a, songRequests) + countAndErase(b, songRequests);

	for (size_t i = 2; i != m; ++i)
	{
		size_t nextSong = (c * b + d * a) % e;
		a = b;
		b = nextSong;
		sCount += countAndErase(nextSong, songRequests);
	}

	std::cout << sCount << std::endl;
}