template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::mulWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).mul(rhs);
}