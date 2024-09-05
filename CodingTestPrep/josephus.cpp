
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include	<queue>

static int solution1(int n, int k)
{
	int remain = n;
	std::vector<int> nums(n, 0);
	std::vector<int> left(n);
	std::vector<int> right(n);
	for (int i = 0; i < n; ++i)
	{
		left[i] = i - 1 < 0 ? n - 1 : i - 1;
		right[i] = i + 1 > n - 1 ? 0 : i + 1;
		nums[i] = i + 1;
	}

	int idx = k - 1;
	while (remain > 1)
	{
		nums[idx] = -1;
		remain--;
		right[left[idx]] = right[idx];
		left[right[idx]] = left[idx];

		for (int i = 0; i < k; ++i)
		{
			idx = right[idx];
		}
	}

	for (const auto num : nums)
	{
		if (-1 != num)
		{
			return num;
		}
	}

	return 0;
}

static int solution2(int n, int k)
{
	std::queue<int> q;
	for (int i = 0; i < n; ++i)
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

void JosephusTest()
{
	int n = 5, k = 2;

	std::cout << "====================== Josephus Test Start ======================" << std::endl;

	std::cout << "N : " << n << ", K : " << k << std::endl;

	int res = solution2(5, 2);

	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Josephus Test End ======================" << std::endl;
}
