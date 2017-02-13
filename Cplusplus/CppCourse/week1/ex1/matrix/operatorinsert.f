template <typename Type>
std::ostream &operator<<(std::ostream &out, Matrix<Type> const &mat)
{
	size_t size = mat.size();
	for (size_t idx = 0; idx != size; idx += mat.d_nCols)
		std::copy(idx, idx + mat.d_nCols,
		          std::ostream_iterator<Type> (out, " "));

	return out;
}