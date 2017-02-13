/*
 * Author: 		Babeanu Alexandru
 * S-number:	s3004872
 * Date:		12-02-2017
 * Challenge:	Paranthesis
 * 
 * Program description:
 * 
 * This program reads a number c, followed by c lines of characters.
 * These characters are right and left sided round and square brackets,
 * and '*'s, representing backspaces. This program checks if the opening
 * and closing brackets match in the right sequence, outputing 'YES' or
 * 'NO' to the standard output accordingly.
 *  
 * Complexity analysis:
 * 
 * Time complexity: O(n), where n is the amount of input characters. The algorithm
 * performs a fixed amount of operations for every input character (the pop and
 * push stack functions are in O(1)). Hence, the complexity is linear.
 * 
 * Memory complexity: O(m), where m is the maximum length among the inputed c lines
 * of characters. Both the string and the stack used in the algorithm have a 
 * maximum length equal to the length of one input line. After one line is
 * processed, the momory used for it is discarded, so the maximum amount of memory
 * used at any given time during runtime is linear in the greatest length of an
 * input line.
 */

#include "main.ih"

int main()
{
	std::ios::sync_with_stdio(false);
	int c; // number of lines
	std::cin >> c;
	std::map<char, char> matchMap({{')', '('}, {']', '['}});
	std::string line;
	try{
		for (; c--;)
		{
			std::cin >> line;
			if (isBalanced(line, matchMap))
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}
	catch(std::out_of_range const& oor)
	{
		std::cerr << "Invalid input\n";
	}
}