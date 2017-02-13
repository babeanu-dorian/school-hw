#include <iostream>

#include "test.h"

using std::cout;

int main()
{
	Test<int> tInt;
	Test<double> tDouble;

	tInt.push(1);
	tInt.push(2);
	tInt.push(3);
	
	tDouble.push(1.1);
	tDouble.push(2.3);
	tDouble.push(5.4);

	cout << tInt.look(tDouble, 2) << '\n';
	cout << tInt.get(0) << ' ' << tInt.get(1) << ' '
		 << tInt.get(2) << ' ' << tDouble.get(0) << ' '
		 << tDouble.get(1) << ' ' << tDouble.get(2) << '\n';
}