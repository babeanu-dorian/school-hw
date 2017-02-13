template <typename LhsType, typename RhsType>
Matrix<LhsType> operator+(Matrix<LhsType> &&lhs, Matrix<RhsType> const &rhs)
{
    Matrix<LhsType> ret(move(lhs));
    ret.add(rhs);
    return ret;
}
