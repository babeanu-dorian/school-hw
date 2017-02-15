template <typename Type>
template <typename IsType>
Ptr<Type>::Ptr(IsType *data)
:
	d_data(data),
	d_deleter(deleter<Type, IsType>)
{}