template <typename Type>
Matrix<Type>::~Matrix()
{
    delete d_data;
}
