
#include	"simulation_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2)
{
	const int size = 3;

	std::vector<std::vector<int>> res(size, std::vector<int>(size));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < size; ++k)
			{
				res[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			std::swap(res[i][j], res[j][i]);
		}
	}

	return res;
}

void MultiplyMatrixAndMakeTransposedTest()
{
	std::vector<std::vector<int>> matrix1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	std::vector<std::vector<int>> matrix2 = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };

	std::cout << "Matrix 1 : " << std::endl;
	for (const auto& ele : matrix1)
	{
		std::cout << "[ ";
		for (const auto& ele2 : ele)
		{
			std::cout << ele2 << " ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Matrix 2 : " << std::endl;
	for (const auto& ele : matrix2)
	{
		std::cout << "[ ";
		for (const auto& ele2 : ele)
		{
			std::cout << ele2 << " ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << std::endl;

	auto res = solution1(matrix1, matrix2);

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
