
#include	"array_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

static std::vector<int> solution1(std::vector<int>& lst)
{
	std::sort(lst.begin(), lst.end(), std::greater<int>());
	//return std::vector<int>(lst.begin(), std::unique(lst.begin(), lst.end()));
	lst.erase(std::unique(lst.begin(), lst.end()), lst.end());
	return lst;
}

void ArrayControlTest()
{
	//std::vector<int> lst = { 4, 2, 2, 1, 3, 4 }; // [4, 3, 2, 1]
	std::vector<int> lst = { 2, 1, 1, 3, 2, 5, 4 }; // [5, 4, 3, 2, 1]

	std::cout << "List : [ ";
	for (const auto& ele : lst)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(lst);
	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
