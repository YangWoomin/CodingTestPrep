
#include	"sort_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

static std::vector<int> solution1(std::vector<int> arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int tmp = arr[i], j = i - 1;
		while (0 <= j)
		{
			if (arr[j] > tmp)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = tmp;
	}

	return arr;
}

void InsertionSortTest()
{
	std::vector<int> arr = { 5, 2, 9, 23, 51, 33, 10, 1, 4 };

	std::cout << "Array : [ ";
	for (const auto& ele : arr)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(arr);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::sort(arr.begin(), arr.end());

	if (arr == res)
	{
		std::cout << "The result is same as std::sort" << std::endl;
	}
	else
	{
		std::cout << "The result is different with std::sort" << std::endl;
		std::cout << "Correct result : [ ";
		for (const auto& ele : arr)
		{
			std::cout << ele << " ";
		}
		std::cout << "]" << std::endl;
	}
}
