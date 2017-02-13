template <typename Type>
template <typename RhsType>
Matrix<Type> &Matrix<Type>::operator+=(Matrix<RhsType> const &rhs) &
{
    add(rhs);
    return *this;
}
