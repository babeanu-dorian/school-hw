template <typename LhsType, typename RhsType>
inline bool operator!=(Matrix<LhsType> const &lhs, Matrix<RhsType> const &rhs)
{
    return not (lhs == rhs);
}