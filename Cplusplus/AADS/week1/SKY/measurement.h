#ifndef INCLUDED_MEASUREMENT_
#define INCLUDED_MEASUREMENT_

#include <stddef.h>

struct Measurement
{
	size_t d_moment;
	size_t d_altitude;

	Measurement(size_t moment, size_t altitude);
};

bool operator==(Measurement const &rhs, Measurement const &lhs);
bool operator<(Measurement const &rhs, Measurement const &lhs);

#endif