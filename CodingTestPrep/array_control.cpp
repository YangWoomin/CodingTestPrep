
#include	"array_test.h"

#include	<iostream>
#include	<vector>
#include	<set>
#include	<algorithm>

static std::vector<int> solution1(std::vector<int> lst)
{
	std::set<int> sorted(lst.begin(), lst.end());
	return std::vector<int>(sorted.rbegin(), sorted.rend());
}

static std::vector<int> solution2(std::vector<int> lst)
{
	std::sort(lst.begin(), lst.end(), [](int lhs, int rhs) 
		{
			return lhs > rhs;
		}
	);

	lst.erase(std::unique(lst.begin(), lst.end()), lst.end());
	return lst;
}

void ArrayControlTest()
{
	std::vector<int> arr = { 4, 5, 2, 9, 4, 3, 3, 2, 1, 7, 9, 8 };

	std::cout << "====================== Array Test Start ======================" << std::endl;

	std::cout << "Test Array : ";
	for (const auto& ele : arr)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::vector<int> res1 = solution1(arr);
	std::cout << "Result 1 by solution 1 : ";
	for (const auto& ele : res1)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::vector<int> res2 = solution2(arr);
	std::cout << "Result 2 by solution 2 : ";
	for (const auto& ele : res2)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::cout << "====================== Array Test End ======================" << std::endl;
}