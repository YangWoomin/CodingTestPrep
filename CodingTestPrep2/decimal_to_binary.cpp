
#include	"stack_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<stack>

static std::string solution1(int decimal)
{
	std::string res;

	std::stack<char> st;

	while (0 < decimal)
	{
		st.push(decimal % 2 + 48);
		decimal /= 2;
	}

	while (!st.empty())
	{
		char c = st.top();
		st.pop();
		res += c;
	}

	return res;
}

void DecimalToBinaryTest()
{
	//int decimal = 10; // "1010"
	//int decimal = 27; // "11011"
	int decimal = 12345; // "11000000111001"

	std::cout << "Decimal : " << decimal << std::endl;

	auto res = solution1(decimal);
	std::cout << "Result : " << res << std::endl;
}
