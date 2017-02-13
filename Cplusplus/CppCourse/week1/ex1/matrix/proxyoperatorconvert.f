template <typename Type>
Matrix<Type>::Proxy::operator Type const &() const
{
	return d_data;
}