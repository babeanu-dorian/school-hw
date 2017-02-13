#ifndef INCLUDED_ADDER_
#define INCLUDED_ADDER_

#include <string>

#include "../binopsbase/binopsbase.h"

class Adder: public BinopsBase<Adder, '+'>
{
	friend class BinopsBase<Adder, '+'>;

	std::string d_value;

	public:
		Adder &operator=(std::string const &rhs);
		std::string const &value() const;

	private:
		void add(Adder const &rhs);

};

#include "value.f"

#endif