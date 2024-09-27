
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static int solution1(std::vector<std::vector<int>> board, std::vector<int> aloc, std::vector<int> bloc) {

    const int max_y = board.size(), max_x = board[0].size();
    const std::vector<int> dir_y = { 1, -1, 0, 0 };
    const std::vector<int> dir_x = { 0, 0, 1, -1 };

    auto isMovable = [&](int y, int x) {
        if (0 > y || max_y <= y || 0 > x || max_x <= x || !board[y][x])
        {
            return false;
        }
        return true;
        };

    std::function<int(int, int, int, int)> dfs = [&](int y, int x, int oy, int ox) {

        if (!board[y][x])
        {
            return 0;
        }

        int bestSteps = 0;

        for (int i = 0; i < 4; ++i)
        {
            int next_y = y + dir_y[i], next_x = x + dir_x[i];
            if (!isMovable(next_y, next_x))
            {
                continue;
            }

            board[y][x] = 0;
            int steps = dfs(oy, ox, next_y, next_x) + 1;
            board[y][x] = 1;

            if (0 == bestSteps % 2 && 1 == steps % 2)
            {
                bestSteps = steps;
            }
            else if (1 == bestSteps % 2 && 1 == steps % 2)
            {
                bestSteps = std::min(bestSteps, steps);
            }
            else if (0 == bestSteps % 2 && 0 == steps % 2)
            {
                bestSteps = std::max(bestSteps, steps);
            }
        }

        return bestSteps;
        };

    return dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
}

void DisappearingFootholdTest()
{
    //std::vector<std::vector<int>> board = { {1, 1, 1} ,{1, 1, 1},{1, 1, 1} };
    //std::vector<int> aloc = { 1, 0 };
    //std::vector<int> bloc = { 1, 2 }; // 5

    //std::vector<std::vector<int>> board = { {1, 1, 1} ,{1, 0, 1},{1, 1, 1 } };
    //std::vector<int> aloc = { 1, 0 };
    //std::vector<int> bloc = { 1, 2 }; // 4

    //std::vector<std::vector<int>> board = { {1, 1, 1, 1, 1} };
    //std::vector<int> aloc = { 0, 0 };
    //std::vector<int> bloc = { 0, 4 }; // 4

    std::vector<std::vector<int>> board = { { 1 } };
    std::vector<int> aloc = { 0, 0 };
    std::vector<int> bloc = { 0, 0 }; // 0

    std::cout << "====================== Disappearing Foothold Test Start ======================" << std::endl;

    std::cout << "Board : " << std::endl;
    for (const auto& ele : board)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    
    std::cout << "A Location : [ " << aloc[0] << ", " << aloc[1] << " ]" << std::endl;
    std::cout << "B Location : [ " << bloc[0] << ", " << bloc[1] << " ]" << std::endl;

    auto res = solution1(board, aloc, bloc);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Disappearing Foothold Test Start ======================" << std::endl;
}
