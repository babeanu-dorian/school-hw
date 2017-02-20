#ifndef INCLUDED_SEQUENCE_
#define INCLUDED_SEQUENCE_

#include <string>
#include <vector>

class Sequence
{

	std::string d_A1;
	std::string d_A2;
	std::vector<size_t> d_seq; // stores the Fibonacci-like sequence
							   // of the lengths of the strings
	
	public:
		Sequence(std::string const &A1, std::string const &A2);
		char operator[](size_t charIdx);

	private:
		size_t findElem(size_t &charIdx);
		char findChar(size_t elIdx, size_t charIdx);
		
};

#endif