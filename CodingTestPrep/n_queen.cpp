
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>

static int solution1(int n) {
    int answer = 0;

    std::vector<int> queen(n, -1);
    std::function<void(int)> dfs = [&](int row) {
        if (row == n)
        {
            answer++;
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            bool next = false;
            for (int i = 0; i < row; ++i)
            {
                if (col == queen[i])
                {
                    next = true;
                    break;
                }

                if (-1 != queen[i] && std::abs(i - row) == std::abs(queen[i] - col))
                {
                    next = true;
                    break;
                }
            }
            if (next)
            {
                continue;
            }

            queen[row] = col;
            dfs(row + 1);
            queen[row] = -1;
        }
        };

    dfs(0);

    return answer;
}

void NQueenTest()
{
    //int n = 4; // 2
    //int n = 5; // 10
    //int n = 6; // 4
    int n = 7; // 40

    std::cout << "====================== N Queen Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== N Queen Test Start ======================" << std::endl;
}

