#include "measurement.h"

bool operator==(Measurement const &rhs, Measurement const &lhs)
{
	return rhs.d_altitude == lhs.d_altitude;
}