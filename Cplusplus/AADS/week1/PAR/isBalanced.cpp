#include "main.ih"

// check if the provided equation is balanced bracket-wise
bool isBalanced(std::string const &eq, std::map<char, char> const &matchMap)
{
	size_t backspace = 0; // count of characters to delete
	std::stack<char> toMatch;

	// iterate equation from end to start
	for (auto rit = eq.rbegin(); rit != eq.rend(); ++rit)
	{
		if (*rit == '*')
			++backspace; // increase count of characters to delete
		else if (backspace)
			--backspace; // ignore current character, decrement delete count
		else
		{
			// right bracket found, push it on the stack
			if (matchMap.count(*rit))
				toMatch.push(*rit);
			// left bracket should find its pair at the top of the stack
			else if (toMatch.empty() || (matchMap.at(toMatch.top()) != *rit))
				return false;
			else 
				toMatch.pop(); // top of stack matched, pop it
		}
	}

	//stack should be empty if all the brackets matched
	return toMatch.empty();
}