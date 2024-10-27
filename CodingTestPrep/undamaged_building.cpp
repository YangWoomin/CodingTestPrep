
#include	"test5.h"

#include	<iostream>
#include	<vector>
#include    <string>



static int solution1(std::vector<std::vector<int>> board, std::vector<std::vector<int>> skill) {
    int answer = 0;

    std::vector<std::vector<int>> diff(board.size() + 1, std::vector<int>(board[0].size() + 1));

    for (const auto& ele : skill)
    {
        int type = ele[0];
        int r1 = ele[1];
        int c1 = ele[2];
        int r2 = ele[3];
        int c2 = ele[4];
        int d = ele[5];

        if (1 == type)
        {
            d *= -1;
        }

        diff[r1][c1] += d;
        diff[r2 + 1][c2 + 1] += d;

        diff[r2 + 1][c1] += -d;
        diff[r1][c2 + 1] += -d;
    }

    for (int i = 0; i < diff.size(); ++i)
    {
        for (int j = 1; j < diff[i].size(); ++j)
        {
            diff[i][j] += diff[i][j - 1];
        }
    }

    for (int i = 1; i < diff.size(); ++i)
    {
        for (int j = 0; j < diff[i].size(); ++j)
        {
            diff[i][j] += diff[i - 1][j];
        }
    }

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            board[i][j] += diff[i][j];
            if (0 < board[i][j])
            {
                answer++;
            }
        }
    }

    return answer;
}

void UndamagedBuildingTest()
{
    //std::vector<std::vector<int>> board = {
    //    {5,5,5,5,5} ,
    //    {5,5,5,5,5},
    //    {5,5,5,5,5},
    //    {5,5,5,5,5}
    //};

    //std::vector<std::vector<int>> skill = {
    //    {1,0,0,3,4,4} ,
    //    {1,2,0,2,3,2},
    //    {2,1,0,3,1,2},
    //    {1,0,1,3,3,1}
    //}; // 10

    std::vector<std::vector<int>> board = {
        {1,2,3} ,
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<int>> skill = {
        {1,1,1,2,2,4} ,
        {1,0,0,1,1,2},
        {2,2,0,2,0,100}
    }; // 6

    std::cout << "====================== Undamaged Building Test Start ======================" << std::endl;

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
    std::cout << std::endl;
    std::cout << "Skill : " << std::endl;
    for (const auto& ele : skill)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(board, skill);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Undamaged Building Test End ======================" << std::endl;
}
