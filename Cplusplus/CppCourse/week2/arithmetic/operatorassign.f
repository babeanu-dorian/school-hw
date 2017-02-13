template <typename Type>
Arithmetic<Type> &Arithmetic<Type>::operator=(Type const &rhs)
{
	d_value = rhs;
	return *this;
}