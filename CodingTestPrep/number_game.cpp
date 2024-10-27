
#include	"test4.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <algorithm>

static int solution1(std::vector<int> A, std::vector<int> B) {
    int answer = 0;

    std::sort(A.rbegin(), A.rend());
    std::sort(B.rbegin(), B.rend());

    int i = 0, j = 0;
    while (i < A.size() && j < B.size())
    {
        if (A[i] >= B[j])
        {
            i++;
        }
        else
        {
            answer++;
            i++, j++;
        }
    }

    return answer;
}

void NumberGameTest()
{
    //std::vector<int> A = { 5,1,3,7 };
    //std::vector<int> B = { 2,2,6,8 }; // 3

    std::vector<int> A = { 2,2,2,2 };
    std::vector<int> B = { 1,1,1,1 }; // 0

    std::cout << "====================== Number Game Test Start ======================" << std::endl;

    std::cout << "A : [ ";
    for (const auto& ele : A)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "B : [ ";
    for (const auto& ele : B)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(A, B);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Number Game Test End ======================" << std::endl;
}
