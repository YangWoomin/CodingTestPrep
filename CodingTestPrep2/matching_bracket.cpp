
#include	"stack_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<stack>

static bool solution1(std::string& s)
{
	std::stack<char> st;

	for (const auto& c : s)
	{
		if ('(' == c)
		{
			st.push(c);
		}
		else
		{
			if (st.empty())
			{
				return false;
			}

			st.pop();
		}
	}

	if (!st.empty())
	{
		return false;
	}

	return true;
}

void MatchingBracketTest()
{
	//std::string s = "(())()"; // true
	std::string s = "((())()"; // false

	std::cout << "Brackets : " << s << std::endl;

	auto res = solution1(s);
	std::cout << "Result : " << res << std::endl;
}
