template <typename Type>
void Arithmetic<Type>::add(Arithmetic<Type> const &rhs)
{
	d_value += rhs.d_value;
}