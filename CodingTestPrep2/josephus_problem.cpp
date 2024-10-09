
#include	"queue_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<queue>

static int solution1(int N, int k)
{
	std::queue<int> q;

	for (int i = 0; i < N; ++i)
	{
		q.push(i + 1);
	}

	while (1 < q.size())
	{
		for (int i = 0; i < k - 1; ++i)
		{
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}

	return q.front();
}

void JosephusProblemTest()
{
	//int N = 5, K = 2; // 3
	int N = 5, K = 2; // 3

	std::cout << "N : " << N << ", K : " << K << std::endl;

	auto res = solution1(N, K);
	std::cout << "Result : " << res << std::endl;
}
