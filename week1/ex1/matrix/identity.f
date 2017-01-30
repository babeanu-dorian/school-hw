template <typename Type>
Matrix<Type> Matrix<Type>::identity(size_t dim) // static
{
    Matrix<Type> ret(dim, dim);

    for (size_t idx = 0; idx != dim; ++idx)
        ret.el(idx, idx) = 1;

    return ret;
}
