
#include	"array_test.h"

#include	<iostream>
#include	<vector>

static std::vector<int> solution1(int n, long long left, long long right) {
    std::vector<int> answer;
    while (left <= right)
    {
        int row = left / n;
        int col = left % n;
        if (row < col)
        {
            answer.push_back(col + 1);
        }
        else
        {
            answer.push_back(row + 1);
        }

        left++;
    }
    return answer;
}


void ArrayCutTest()
{
	//int n = 3, left = 2, right = 5; // [3,2,2,3]
    int n = 4, left = 7, right = 14; // [4,3,3,3,4,4,4,4]

	std::cout << "====================== Array Cut Test Start ======================" << std::endl;

	std::cout << "N : " << n << ", Left : " << left << ", Right : " << right << std::endl;

	std::vector<int> res = solution1(n, left, right);
	std::cout << "Result : ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << std::endl;

	std::cout << "====================== Array Cut Test End ======================" << std::endl;
}
