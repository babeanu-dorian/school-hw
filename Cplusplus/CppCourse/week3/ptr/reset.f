template <typename Type>
template <typename IsType>
void Ptr<Type>::reset(IsType *data)
{
	d_deleter(d_data);
	d_data = data;
	d_deleter = deleter<Type, IsType>;
}