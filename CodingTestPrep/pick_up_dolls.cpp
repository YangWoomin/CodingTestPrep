
#include	"stack_test.h"

#include	<iostream>
#include	<vector>
#include	<stack>

static int solution1(const std::vector<std::vector<int>>& board, const std::vector<int>& moves) {
    int answer = 0;

    std::stack<int> bucket;
    std::vector<int> access(board.size(), -1);

    for (const auto& ele : moves)
    {
        int pickCol = ele - 1;
        if (-1 == access[pickCol])
        {
            int idx = 0;
            while (0 == board[idx][pickCol] && idx < board.size())
            {
                ++idx;
            }

            access[pickCol] = idx;
        }

        if (board.size() == access[pickCol])
        {
            continue;
        }

        bool push = false;
        if (true == bucket.empty())
        {
            push = true;
        }
        else
        {
            int last = bucket.top();
            if (last == board[access[pickCol]][pickCol])
            {
                bucket.pop();
                answer++;
            }
            else
            {
                push = true;
            }
        }

        if (true == push)
        {
            bucket.push(board[access[pickCol]][pickCol]);
        }

        access[pickCol] += 1;
    }

    return answer * 2;
}

void PickUpDollsTest()
{
    std::vector<std::vector<int>> board = {
        { 0,0,0,0,0 },
        { 0,0,1,0,3 },
        { 0,2,5,0,1 },
        { 4,2,4,4,2 },
        { 3,5,1,3,1 }
    };

    std::vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 }; // 4

    std::cout << "====================== Pick Up Dolls Test Start ======================" << std::endl;

    std::cout << "Board : ";
    for (const auto& row : board)
    {
        std::cout << "[ ";

        for (const auto& col : row)
        {
            std::cout << col << " ";
        }

        std::cout << " ]" << std::endl;
    }
    std::cout << "Moves : [ ";
    for (const auto& ele : moves)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    int res = solution1(board, moves);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Pick Up Dolls Test End ======================" << std::endl;
}
