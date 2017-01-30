template <typename Type>
template <typename RhsType>
void Matrix<Type>::add(Matrix<RhsType> const &rhs)
{
    if (d_nRows != rhs.d_nRows || d_nCols != rhs.d_nCols)
    {
        std::cerr << "Cannot add matrices of unequal dimensions\n";
        exit(1);
    }

    for (size_t idx = 0, end = size(); idx != end; ++idx)
        d_data[idx] += rhs.d_data[idx];
}