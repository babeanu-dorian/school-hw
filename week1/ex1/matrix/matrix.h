#ifndef INCLUDED_MATRIX_
#define INCLUDED_MATRIX_

#include <iostream>
#include <cstring>
#include <initializer_list>
#include <algorithm>
#include <iterator>

template <typename Type>
class Matrix
{
	template <typename Other>
	friend class Matrix;

    size_t d_nRows = 0;
    size_t d_nCols = 0;
    Type *d_data = 0;

    class Proxy
    {
        Type *d_data;
    
        Proxy(Type *data);
	    Proxy &operator=(Proxy const &other);    // 1
	    Proxy &operator=(Type const &value);     // 2
	    operator Type const &() const;
    };

    public:

        typedef std::initializer_list<std::initializer_list<Type>> IniList;

        Matrix() = default;
        Matrix(size_t nRows, size_t nCols);         // 1
        Matrix(Matrix<Type> const &other);          // 2
        Matrix(Matrix<Type> &&tmp);                 // 3
        Matrix(IniList inilist);                    // 4

        ~Matrix();

        Matrix<Type> &operator=(Matrix<Type> const &rhs);
        Matrix<Type> &operator=(Matrix<Type> &&tmp);


        size_t nRows() const;
        size_t nCols() const;
        size_t size() const;            // nRows * nCols

        static Matrix<Type> identity(size_t dim);

        Matrix<Type> &tr();             // transpose (must be square)
        Matrix<Type> transpose() const; // any dim.

        void swap(Matrix<Type> &other);

        Proxy operator[](size_t idx);

        template <typename RhsType>
        Matrix<Type> &operator+=(Matrix<RhsType> const &rhs)   &; // 1

        template <typename RhsType>
        Matrix<Type> &&operator+=(Matrix<RhsType> const &rhs) &&; // 2

    private:
    	template <typename LhsType, typename RhsType>
        friend Matrix<LhsType> operator+(Matrix<LhsType> const &lhs,
                                         Matrix<RhsType> const &rhs);  // 1

        template <typename LhsType, typename RhsType>
        friend Matrix<LhsType> operator+(Matrix<LhsType> &&lhs,
                                         Matrix<RhsType> const &rhs);  // 2

        template <typename RhsType>
        void add(Matrix<RhsType> const &rhs);

        template <typename LhsType, typename RhsType>
        friend bool operator==(Matrix<LhsType> const &lhs, Matrix<RhsType> const &rhs);

        Type &el(size_t row, size_t col) const;

        template <typename RhsType>
        friend std::ostream &operator<<(std::ostream &out, Matrix<RhsType> const &mat);

        template <typename RhsType>
        friend std::istream &operator>>(std::istream &in,  Matrix<RhsType> &mat);

};

#include "add.f"
#include "destructor.f"
#include "el.f"
#include "identity.f"
#include "matrix1.f"
#include "matrix2.f"
#include "matrix3.f"
#include "matrix4.f"
#include "ncols.f"
#include "nrows.f"
#include "operatoradd1.f"
#include "operatoradd2.f"
#include "operatoraddis1.f"
#include "operatoraddis2.f"
#include "operatorassign1.f"
#include "operatorassign2.f"
#include "operatorequal.f"
#include "operatorextract.f"
#include "operatorindex.f"
#include "operatorinsert.f"
#include "operatornotequal.f"
#include "proxy.f"
#include "proxyoperatorassign1.f"
#include "proxyoperatorassign2.f"
#include "proxyoperatorconvert.f"
#include "size.f"
#include "swap.f"
#include "tr.f"
#include "transpose.f"

#endif