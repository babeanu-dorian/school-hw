#ifndef INCLUDED_ARITHMETIC_
#define INCLUDED_ARITHMETIC_

#include <type_traits>

#include "../binopsbase/binopsbase.h"

template <typename Type>
class Arithmetic: public BinopsBase<Arithmetic<Type>, '+', '-', '*'>
{
	static_assert(std::is_same<Type, int>::value ||
				  std::is_same<Type, double>::value,
				  "Arithmetic should only be used for int or double.");

	friend class BinopsBase<Arithmetic<Type>, '+', '-', '*'>;

	Type d_value;

	public:
		Arithmetic &operator=(Type const &rhs);
		Type const &value() const;

	private:
		void add(Arithmetic const &rhs);
		void sub(Arithmetic const &rhs);
		void mul(Arithmetic const &rhs);

};

#include "add.f"
#include "sub.f"
#include "mul.f"
#include "operatorassign.f"
#include "value.f"

#endif