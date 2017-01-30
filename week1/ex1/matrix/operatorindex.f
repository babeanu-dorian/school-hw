template <typename Type>
inline typename Matrix<Type>::Proxy Matrix<Type>::operator[](size_t idx)
{
    return typename Matrix<Type>::Proxy{&el(idx, 0)};
}