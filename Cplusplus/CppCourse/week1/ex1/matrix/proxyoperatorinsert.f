template <typename Type>
std::ostream &operator<<(std::ostream &out, Matrix<Type>::Proxy &prox)
{
    return out << *prox.d_data;
}