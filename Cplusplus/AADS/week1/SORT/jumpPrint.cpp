#include "main.ih"

void jumpPrint(std::vector<size_t> arr, size_t jump)
{
	for (size_t i = 0; i < arr.size(); i += jump)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}