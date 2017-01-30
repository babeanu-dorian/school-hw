template <typename Type>
std::istream &operator>>(std::istream &in,  Matrix<Type> &mat)
{
	size_t size = mat.size();
	for (size_t idx = 0; idx != size; ++idx)
		in >> mat.d_data[idx];
	
	return in;
}