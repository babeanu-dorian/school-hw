/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		18-02-2017
 * Challenge:	Sky tour
 * 
 * Program description:
 * 
 * This program reads two integers, n (the number of querries) and m (limit on
 * measurements recorded). It also reads n querries. If the querry starts with
 * a 1, 2 integers are read and their difference is stored along its index
 * in the chronological order of all measurements. If the querry starts with
 * a 2, the first highest m measurements are printed chronologically.
 *  
 * Complexity analysis:
 * 
 * Time complexity: Since the complexities of pop and push on the priority queue
 * are log(m), the complexity of find is O(m) and the complexities of erase and
 * push_back on the list are O(1), the time complexity for an input querry of
 * type 1 is O(2 * log(m) + O(m) + 2 * O(1)) = O(m). The time complexity for
 * printing the list of size m is O(m). The total complexity, for all n querries,
 * is O(n * m).
 * 
 * Memory complexity: The program stores only m elements in the priority queue and
 * m elements in the list (excluding the constant amount of other variables).
 * Total space comlexity: O(2 * m) = O(m).
 */

#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

#include "measurement.h"

int main()
{
	std::ios::sync_with_stdio(false);
	size_t n, m;

	std::cin >> n >> m;

	// lowest altitude at the top
	std::priority_queue<Measurement> topHits;

	// chronological order of the items in topHits
	std::list<Measurement> chronoOrder;

	size_t moment = 0;
	for (; n--;)
	{
		size_t t;
		std::cin >> t;
		if (t == 1)   // add new measurement
		{
			size_t g, b;
			std::cin >> g >> b;
			Measurement cur(++moment, b - g);

			if (topHits.size() == m)
			{
				// compare new measurement with the smallest recorded altitude
				if (topHits.top().d_altitude <= cur.d_altitude)
				{
					// new measurement greater, remove minimum, push the new one
					chronoOrder.erase(std::find(chronoOrder.begin(),
									  chronoOrder.end(), topHits.top()));
					chronoOrder.push_back(cur);
					topHits.pop();
					topHits.push(cur);
				}
			}
			else
			{
				topHits.push(cur);
				chronoOrder.push_back(cur);
			}
		}
		else   // print m measurements
		{
			for (auto it = chronoOrder.begin(); it != chronoOrder.end(); ++it)
				std::cout << it->d_moment << ' ' << it->d_altitude << std::endl;
			std::cout << std::endl;
		}
	}
}