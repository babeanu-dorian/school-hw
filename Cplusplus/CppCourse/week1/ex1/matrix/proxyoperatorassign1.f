template <typename Type>
typename Matrix<Type>::Proxy &Matrix<Type>::Proxy::operator=(Proxy const &other)
{
	*d_data = *other.d_data;
	return *this;
}