
#include	"tree_test.h"

#include	<iostream>

static int solution1(int n, int a, int b)
{
	int answer = 0;

	a--;
	b--;

	while (a != b)
	{
		a >>= 1;
		b >>= 1;
		answer++;
	}

	return answer;
}

void PredictMatchTest()
{
	int n = 8, a = 4, b = 7; // 3

	std::cout << "====================== Predict Match Test Start ======================" << std::endl;

	std::cout << "N : " << n << ", A : " << a << ", B : " << b << std::endl;

	auto res = solution1(n, a, b);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Predict Match Test End ======================" << std::endl;
}
