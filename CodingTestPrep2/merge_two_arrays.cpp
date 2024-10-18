
#include	"sort_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<int> solution1(std::vector<int> arr1, std::vector<int> arr2)
{
	std::vector<int> res;

	int i = 0, j = 0;
	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] < arr2[j])
		{
			res.push_back(arr1[i]);
			i++;
		}
		else
		{
			res.push_back(arr2[j]);
			j++;
		}
	}

	while (i < arr1.size())
	{
		res.push_back(arr1[i]);
		i++;
	}

	while (j < arr2.size())
	{
		res.push_back(arr2[j]);
		j++;
	}

	return res;
}

void MergeTwoArraysSortTest()
{
	std::vector<int> arr1 = { 1, 3, 5 };
	std::vector<int> arr2 = { 2, 4, 6 };

	std::cout << "Array 1 : [ ";
	for (const auto& ele : arr1)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Array 2 : [ ";
	for (const auto& ele : arr2)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(arr1, arr2);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
