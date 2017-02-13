template <typename Type>
void Matrix<Type>::swap(Matrix<Type> &other)
{
    char buffer[sizeof(Matrix<Type>)];
    memcpy(buffer, this,   sizeof(Matrix<Type>));
    memcpy(this,   &other, sizeof(Matrix<Type>));
    memcpy(&other, buffer, sizeof(Matrix<Type>));
}
