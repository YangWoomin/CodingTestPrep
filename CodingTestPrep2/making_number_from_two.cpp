
#include	"hash_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<unordered_set>

static bool solution1(std::vector<int> arr, int target)
{
	std::unordered_set<int> set;

	for (const auto& ele : arr)
	{
		if (set.end() != set.find(target - ele))
		{
			return true;
		}
		set.insert(ele);
	}

	return false;
}

void MakingNumberFromTwoTest()
{
	//std::vector<int> arr = { 1, 2, 3, 4, 8 };
	//int target = 6; // true

	std::vector<int> arr = { 2, 3, 5, 9 };
	int target = 10; // false

	std::cout << "Array : [ ";
	for (const auto& ele : arr)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Target : " << target << std::endl;

	auto res = solution1(arr, target);

	std::cout << "Result : " << res << std::endl;
}
