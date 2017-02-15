template <typename Type>
Ptr<Type>::~Ptr()
{
	d_deleter(d_data);
}