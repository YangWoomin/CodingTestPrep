
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_set>

static bool solution1(std::vector<int> arr, int target)
{
	std::unordered_set<int> set(target);

	for (const auto& ele : arr)
	{
		int sample = target - ele;
		if (set.end() != set.find(sample))
		{
			return true;
		}
		else
		{
			set.insert(ele);
		}
	}

	return false;
}

void SpecificValueFromTwoValuesTest()
{
	std::vector<int> arr = { 1, 2, 3, 4, 8 };
	int target = 6; // true

	/*std::vector<int> arr = { 2, 3, 5, 9 };
	int target = 10; // false */

	std::cout << "====================== Specific Value From Two Values Test Start ======================" << std::endl;
	
	std::cout << "Values : [ ";
	for (const auto& ele : arr)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

	bool res = solution1(arr, target);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Specific Value From Two Values Test End ======================" << std::endl;
}
