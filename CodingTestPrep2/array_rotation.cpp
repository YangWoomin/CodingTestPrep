
#include	"simulation_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> arr, int n)
{
	const int size = arr.size();

	for (int i = 0; i < n % 4; ++i)
	{
		for (int j = 0; j < size / 2; ++j)
		{
			for (int k = j; k < size - j - 1; ++k)
			{
				int tmp = arr[j][k];
				arr[j][k] = arr[size - 1 - k][j];
				arr[size - 1 - k][j] = arr[size - 1 - j][size - 1 - k];
				arr[size - 1 - j][size - 1 - k] = arr[k][size - 1 - j];
				arr[k][size - 1 - j] = tmp;
			}
		}
	}

	return arr;
}

static std::vector<std::vector<int>> solution2(std::vector<std::vector<int>> arr, int n)
{
	const int size = arr.size();

	std::vector<std::vector<int>> tmp(size, std::vector<int>(size));

	for (int i = 0; i < n % 4; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < size; ++k)
			{
				tmp[k][size - 1 - j] = arr[j][k];
			}
		}
		arr = tmp;
	}

	return arr;
}

void ArrayRotationTest()
{
	std::vector<std::vector<int>> arr = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	int n = 3;

	std::cout << "Array : " << std::endl;
	for (const auto& ele : arr)
	{
		std::cout << "[ ";
		for (const auto& ele2 : ele)
		{
			std::cout << ele2 << " ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;

	auto res = solution2(arr, n);

	std::cout << "Result : " << std::endl;
	for (const auto& ele : res)
	{
		std::cout << "[ ";
		for (const auto& ele2 : ele)
		{
			std::cout << ele2 << " ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;
}
