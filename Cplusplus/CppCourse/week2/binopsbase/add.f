template <class Derived>
class Add
{
    public:
        Derived &operator+=(Derived const &rhs) &; 
        Derived &&operator+=(Derived const &rhs) &&;
};

template <class Derived>
Derived &Add<Derived>::operator+=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.addWrap(rhs);
    std::swap(static_cast<Derived &>(*this), tmp);
    return static_cast<Derived &>(*this);
}

template <class Derived>
Derived &&Add<Derived>::operator+=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).addWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator+(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.addWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator+(Derived &&lhs, Derived const &rhs)
{
    lhs.addWrap(rhs);
    return std::move(lhs);
}


template <class Binops, class Derived, int ...ops>
class BinopsBase0<Binops, Derived, '+', ops...>
:
    public BinopsBase0<Binops, Derived, ops...>,
    public Add<Derived>
{};



