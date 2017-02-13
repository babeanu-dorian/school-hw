template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::addWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).add(rhs);
}