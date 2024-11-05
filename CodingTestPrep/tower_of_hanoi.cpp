
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <functional>

static std::vector<std::vector<int>> solution1(int n) {
    std::vector<std::vector<int>> answer;

    std::function<void(int, int, int, int)> hanoi = [&](int from, int tmp, int to, int num) {

        if (0 == num)
        {
            return;
        }

        hanoi(from, to, tmp, num - 1);
        answer.push_back({ from, to });
        hanoi(tmp, from, to, num - 1);
        };

    hanoi(1, 2, 3, n);

    return answer;
}

void TowerOfHanoiTest()
{
    int n = 2; // [ [1,2], [1,3], [2,3] ]

    std::cout << "====================== Tower Of Hanoi Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << std::endl;
    for (const auto& ele : res)
    {
        std::cout << "[ " << ele[0] << " " << ele[1] << " ]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====================== Tower Of Hanoi Test End ======================" << std::endl;
}
