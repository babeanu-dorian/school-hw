template <typename Type>
typename Matrix<Type>::Proxy &Matrix<Type>::Proxy::operator=(Type const &value)
{
	*d_data = value;
	return *this;
}