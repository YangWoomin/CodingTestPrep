
#include	"recursive_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<functional>

static int solution1(int n)
{
    int answer = 0;

    std::function<void(char, char, char, int)> hanoi = [&](char from, char via, char to, int num) {

        if (0 == num)
        {
            return;
        }

        hanoi(from, to, via, num - 1);
        std::cout << num << " : " << from << " to " << to << std::endl;
        answer++;
        hanoi(via, from, to, num - 1);
    };

    hanoi('A', 'B', 'C', n);

    return answer;
}

void TowerOfHanoiTest()
{
    int n = 3;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;
}
