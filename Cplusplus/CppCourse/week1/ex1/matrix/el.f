template <typename Type>
inline Type &Matrix<Type>::el(size_t row, size_t col) const
{
    return d_data[row * d_nCols + col];
}