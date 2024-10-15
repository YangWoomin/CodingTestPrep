
#include	"backtracking_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<std::vector<int>> solution1(int N)
{
	std::vector<std::vector<int>> answers;
	std::vector<int> answer;
	std::function<void(int, int)> dfs = [&](int num, int sum) {
		
		if (N < num || 10 <= sum)
		{
			if (10 == sum)
			{
				answers.push_back(answer);
			}
			return;
		}

		answer.push_back(num);
		dfs(num + 1, num + sum);
		answer.pop_back();
		dfs(num + 1, sum);
	};

	dfs(1, 0);

	return answers;
}

void _10CombinationTest()
{
	//int N = 5; // [[1 2 3 4] [1 4 5] [2 3 5]]
	//int N = 2; // []
	int N = 7; // [[1 2 3 4] [1 2 7] [1 3 6] [1 4 5] [2 3 5] [3 7] [4 6]]

	std::cout << "N : " << N << std::endl;

	auto res = solution1(N);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << "[ ";
		for (const auto& ele2 : ele)
		{
			std::cout << ele2 << " ";
		}
		std::cout << "] ";
	}
	std::cout << "]" << std::endl;
}
