
#include	"stack_test.h"

#include	<iostream>
#include	<string>
#include	<stack>

static std::string solution1(int decimal)
{
	std::string ret;
	std::stack<char> res;

	while (decimal != 0)
	{
		res.push(decimal % 2 == 0 ? '0' : '1');
		decimal /= 2;
	}
	
	while (false == res.empty())
	{
		ret += res.top();
		res.pop();
	}

	return ret;
}

void DecimalToBinaryTest()
{
	//int decimal = 10; // "1010"
	//int decimal = 27; // "11011"
	int decimal = 12345; // "11000000111001"

	std::cout << "====================== Decimal to Binary Test Start ======================" << std::endl;

	std::cout << "Decimal : " << decimal << std::endl;

	std::string res = solution1(decimal);

	std::cout << "Binary : " << res << std::endl;

	std::cout << "====================== Decimal to Binary Test End ======================" << std::endl;
}
