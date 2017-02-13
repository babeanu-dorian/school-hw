template <typename Type>
Matrix<Type>::Matrix(Matrix<Type> &&tmp)
{
    swap(tmp);
}
