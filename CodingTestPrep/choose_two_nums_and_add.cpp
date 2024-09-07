
#include	"array_test.h"

#include	<iostream>
#include	<vector>
#include	<set>

static std::vector<int> solution1(std::vector<int> arr)
{
	std::set<int> res;

	for (auto i = 0; i < arr.size(); ++i)
	{
		for (auto j = i + 1; j < arr.size(); ++j)
		{
			res.insert(arr[i] + arr[j]);
		}
	}

	return std::vector<int>(res.begin(), res.end());
}

void ChooseTwoNumsAndAddTest()
{
	//std::vector<int> arr = { 2, 1, 3, 4, 1 }; // [2,3,4,5,6,7]
	std::vector<int> arr = { 5, 0, 2, 7 }; // [2,5,7,9,12]

	std::cout << "====================== Choose Two Nums And Add Test Start ======================" << std::endl;

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

	std::cout << "====================== Choose Two Nums And Add Test End ======================" << std::endl;
}
