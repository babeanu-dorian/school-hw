template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::subWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).sub(rhs);
}