#include "sequence.h"

Sequence::Sequence(std::string const &A1, std::string const &A2)
:
	d_A1(A1),
	d_A2(A2),
	d_seq({A1.size(), A2.size()})
{}