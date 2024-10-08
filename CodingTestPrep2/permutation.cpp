
#include	"array_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>


static bool solution1(std::vector<int>& arr)
{
	return std::next_permutation(arr.begin(), arr.end());
}

static bool solution2(std::vector<int>& arr)
{
	const int size = arr.size();
	int i = size - 2;
	while (0 <= i && arr[i] > arr[i + 1])
	{
		i--;
	}

	if (0 > i)
	{
		return false;
	}

	int j = size - 1;
	while (0 < j && arr[i] > arr[j])
	{
		j--;
	}

	std::swap(arr[i], arr[j]);
	i++;
	j = size - 1;

	while (i < j)
	{
		std::swap(arr[i], arr[j]);
		i++, j--;
	}

	return true;
}

void PermutationTest()
{
	std::vector<int> arr = { 1, 2, 3, 4, 5 };

	std::cout << "Array : [ ";
	for (const auto& ele : arr)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	int i = 1;
	auto arr1 = arr, arr2 = arr;
	while (solution1(arr1) && solution2(arr2) && arr1 == arr2)
	{
		std::cout << i << " : [ ";
		for (const auto& ele : arr2)
		{
			std::cout << ele << " ";
		}
		std::cout << "]" << std::endl;
		i++;
	}
}
