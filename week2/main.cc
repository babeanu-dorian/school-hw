#include "main.ih"

int main()
{
	Arithmetic<int> x;
	Arithmetic<int> y;
	x = 1;
	y = 2;

	Arithmetic<int> sum(x + y);
	Arithmetic<int> dif(x - y);
	Arithmetic<int> prod(x * y);

	sum += x + (x + y);
	sum += sum;
	dif -= x;
	dif -= x - (x - y);
	prod *= x * y * x;
	prod *= prod;

	cout << "Sum: " << sum.value() << '\n'     // 14
		 << "Dif: " << dif.value() << '\n'     // -4
		 << "Prod: " << prod.value() << '\n';  // 16
}