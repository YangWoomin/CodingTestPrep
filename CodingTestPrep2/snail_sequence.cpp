
#include	"simulation_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

static std::vector<std::vector<int>> solution1(int n)
{
	std::vector<std::vector<int>> res(n, std::vector<int>(n));

	int count = 1;
	int i = 0, j = 0;
	while (n * n >= count)
	{
		while (j < n && !res[i][j])
		{
			res[i][j] = count++;
			j++;
		}
		j--, i++;

		while (i < n && !res[i][j])
		{
			res[i][j] = count++;
			i++;
		}
		i--, j--;

		while (j >= 0 && !res[i][j])
		{
			res[i][j] = count++;
			j--;
		}
		j++, i--;

		while (i >= 0 && !res[i][j])
		{
			res[i][j] = count++;
			i--;
		}
		i++, j++;
	}

	return res;
}

void SnailSequenceTest()
{
	int n = 4;

	std::cout << "N : " << n << std::endl;

	auto res = solution1(n);

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
