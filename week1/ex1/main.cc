#include <iostream>

#include "matrix/matrix.h"

using std::cout;

int main()
{
	Matrix<double> m({{1.2, 1.3, 1.4},
					 {2.3, 2.4, 2.5},
					 {3.4, 4.5, 5.6}});

	double x = m[2][1];

	cout << m <<'\n' << x << '\n';

	//cout << m[2][1] << '\n';
}