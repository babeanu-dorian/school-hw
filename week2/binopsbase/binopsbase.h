#ifndef INCLUDED_BINOPSBASE_
#define INCLUDED_BINOPSBASE_

#include <utility>

// general case:
template <class Binops, class Derived, int ...ops>
class BinopsBase0;

// base case:
template <class Binops, class Derived>
class BinopsBase0<Binops, Derived>
{};

#include "add.f"
#include "sub.f"
#include "mul.f"

template <class Derived, int ...ops>
class BinopsBase:
	public BinopsBase0<BinopsBase<Derived, ops...>, Derived, ops...>
{
	friend Add<Derived>;
    friend Sub<Derived>;
	friend Mul<Derived>;

	friend Derived operator+<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator+<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator-<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator-<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator*<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator*<Derived>(Derived &&lhs, Derived const &rhs);

    void addWrap(Derived const &rhs);
    void mulWrap(Derived const &rhs);
    void subWrap(Derived const &rhs);
};

#include "addwrap.f"
#include "subwrap.f"
#include "mulwrap.f"

#endif