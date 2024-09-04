
#include	"stack_test.h"

#include	<iostream>
#include	<string>

static bool solution1(const std::string& s)
{
	int count = 0;

	for (const auto& ele : s)
	{
		if ('(' == ele)
		{
			count++;
		}
		else // (')' == ele)
		{
			count--;
		}
	}

	return 0 == count;
}

void BracketMatchTest()
{
	//std::string s = "(())()";
	std::string s = "((())()";

	std::cout << "====================== Bracket Match Test Start ======================" << std::endl;

	std::cout << "Bracket : " << s << std::endl;

	bool res = solution1(s);

	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Bracket Match Test End ======================" << std::endl;
}
