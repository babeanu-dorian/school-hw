template <typename LhsType, typename RhsType>
Matrix<LhsType> operator+(Matrix<LhsType> const &lhs, Matrix<RhsType> const &rhs)
{
    Matrix<LhsType> ret(lhs);
    ret.add(rhs);
    return ret;
}
