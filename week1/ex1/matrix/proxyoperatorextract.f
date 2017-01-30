template <typename T>
std::istream &operator>>(std::istream &in, Matrix<T>::Proxy &prox)
{
    return in >> *prox.d_data;
}