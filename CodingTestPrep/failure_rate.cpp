
#include	"array_test.h"

#include	<iostream>
#include	<vector>
#include	<map>

static std::vector<int> solution1(int N, std::vector<int>& stages)
{
	std::vector<int> status(N + 1, 0);

	for (auto i = 0; i < stages.size(); ++i)
	{
		status[stages[i] - 1] += 1;
	}

	int reachUserNum = status[status.size() - 1];
	std::map<float, std::vector<int>> res;
	for (int i = status.size() - 2; i >= 0; --i)
	{
		reachUserNum += status[i];

		float key = 0.f;
		if (0 < reachUserNum)
		{
			key = (float)status[i] / reachUserNum;
		}
		
		auto it = res.insert(std::make_pair(key, std::vector<int>(1, i + 1)));
		if (false == it.second)
		{
			it.first->second.push_back(i + 1);
		}
	}

	std::vector<int> ret;
	for (auto it = res.rbegin(); res.rend() != it; ++it)
	{
		ret.insert(ret.end(), it->second.rbegin(), it->second.rend());
	}
	return ret;

}

void FailureRateTest()
{
	int N = 5;
	std::vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	/*int N = 4;
	std::vector<int> stages = { 4, 4, 4, 4, 4 };*/

	std::cout << "====================== Failure Rate Test Start ======================" << std::endl;

	std::cout << "Stage Num : " << N << std::endl;
	std::cout << "Current Stages : ";
	for (const auto& ele : stages)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::vector<int> res = solution1(N, stages);
	std::cout << "Result of Failure Rate Order : ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::cout << "====================== Failure Rate Test End ======================" << std::endl;
}
