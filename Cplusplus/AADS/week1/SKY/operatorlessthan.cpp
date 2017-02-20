#include "measurement.h"

// makes sure the measurement with the lowest altitude has the highest priority
bool operator<(Measurement const &rhs, Measurement const &lhs)
{
	return rhs.d_altitude > lhs.d_altitude;
}