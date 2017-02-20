#include "main.ih"

// order = k = order of the hilbert curve
// middle = 2^k = x and y coordinate of the origin of the bottom-right quarter
// x and y = coordinates of the point (origin has moved to (0, 0))
unsigned long long hilbertDist(size_t order, unsigned long long middle,
	                           unsigned long long x, unsigned long long y)
{
	if (order == 0)
		return 0;

	if (x < middle)
	{
		if (y < middle) // top-left quarter, flip on the 1st diagonal
			return hilbertDist(order - 1, middle >> 1, y, x);
		else  // bottom-left quarter, add 4^(k-1) , shift vertically by 2^(k-1)
			return middle * middle + hilbertDist(order - 1, middle >> 1, x,
				                                 y - middle);
	}
	else
	{
		if (y < middle)
			// top-right quarter, add 3*4^(k-1), shift horizontally by 2^(k-1),
			// flip on the 2nd diagonal
			return 3 * middle * middle + hilbertDist(order - 1, middle >> 1,
				            middle - y - 1,(middle << 1) - x - 1);
		else
			// bottom-right quarter, add 3*4^(k-1),
			// shift both horizontally and vertically by 2^(k-1)
			return 2 * middle * middle + hilbertDist(order - 1, middle >> 1,
				                                     x - middle, y - middle);
	}
}