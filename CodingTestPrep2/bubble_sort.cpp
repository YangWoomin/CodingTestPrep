
#include	"sort_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<int> solution1(std::vector<int> arr)
{
	for (int i = arr.size() - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	return arr;
}

void BubbleSortTest()
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
