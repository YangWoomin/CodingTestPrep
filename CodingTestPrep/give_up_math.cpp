
#include	"tests.h"

#include	<iostream>
#include	<vector>
#include	<map>
#include	<algorithm>


static std::vector<int> solution1(std::vector<int>& user1, std::vector<int>& user2, std::vector<int>& user3, std::vector<int>& answers)
{
	std::vector<int> hits(3, 0);

	for (auto i = 0; i < answers.size(); ++i)
	{
		if (user1[i % user1.size()] == answers[i])
		{
			hits[0]++;
		}
		if (user2[i % user2.size()] == answers[i])
		{
			hits[1]++;
		}
		if (user3[i % user3.size()] == answers[i])
		{
			hits[2]++;
		}
	}

	const int max = *std::max_element(hits.begin(), hits.end());

	std::vector<int> res;
	for (auto i = 0; i < hits.size(); ++i)
	{
		if (max == hits[i])
		{
			res.push_back(i + 1);
		}
	}

	return res;
}

void GiveUpMathTest()
{
	std::vector<int> user1 = { 1, 2, 3, 4, 5 };
	std::vector<int> user2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	std::vector<int> user3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	//std::vector<int> answers = { 1, 2, 3, 4, 5 };
	std::vector<int> answers = { 1, 3, 2, 4, 2 };

	std::cout << "====================== Give Up Math Test Start ======================" << std::endl;

	std::cout << "Test Answers : ";
	for (const auto& ele : answers)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::vector<int> res1 = solution1(user1, user2, user3, answers);
	std::cout << "Result 1 by solution 1 : ";
	for (const auto& ele : res1)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;


	std::cout << "====================== Give Up Math Test End ======================" << std::endl;
}
