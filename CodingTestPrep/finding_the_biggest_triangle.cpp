
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

// brute force
static int solution1(std::vector<std::vector<int>> board)
{
    if (0 == board.size())
    {
        return 0;
    }

    int answer = 0;

    const int width = board[0].size(), height = board.size();

    std::vector<std::vector<int>> row(height, std::vector<int>(width));
    std::vector<std::vector<int>> col(height, std::vector<int>(width));

    for (int i = 0; i < height; ++i)
    {
        int sum = 0;
        for (int j = 0; j < width; ++j)
        {
            if (board[i][j])
            {
                sum++;
            }
            else
            {
                sum = 0;
            }
            row[i][j] = sum;
        }
    }

    for (int i = 0; i < width; ++i)
    {
        int sum = 0;
        for (int j = 0; j < height; ++j)
        {
            if (board[j][i])
            {
                sum++;
            }
            else
            {
                sum = 0;
            }
            col[j][i] = sum;
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int len = std::min(row[i][j], col[i][j]);
            for (int k = 0; k < len; ++k)
            {
                int l = len - k;
                if (l > row[i - k][j - k] || l > col[i - k][j - k])
                {
                    break;
                }
                else if (len - 1 == k)
                {
                    answer = std::max(answer, len);
                }
            }
        }
    }

    return answer * answer;
}

// dp 1
static int solution2(std::vector<std::vector<int>> board)
{
    if (0 == board.size())
    {
        return 0;
    }

    int answer = 0;

    const int width = board[0].size(), height = board.size();
    std::vector<std::vector<int>> dp(height, std::vector<int>(width));

    for (int i = 0; i < height; ++i)
    {
        int sum = 0;
        for (int j = 0; j < width; ++j)
        {
            if (board[i][j])
            {
                sum++;
            }
            else
            {
                sum = 0;
            }
            dp[i][j] = sum;
        }
    }

    for (int i = 0; i < width; ++i)
    {
        int sum = 0;
        for (int j = 0; j < height; ++j)
        {
            if (board[j][i])
            {
                sum++;
            }
            else
            {
                sum = 0;
            }

            dp[j][i] = std::min(sum, dp[j][i]);
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (0 < i && 0 < j)
            {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            answer = std::max(answer, dp[i][j]);
        }
    }

    return answer * answer;
}

// dp 2
static int solution3(std::vector<std::vector<int>> board)
{
    int answer = 0;

    const int height = board.size(), width = board[0].size();

    for (int h = 0; h < height; ++h)
    {
        for (int w = 0; w < width; ++w)
        {
            if (0 < h && 0 < w && 0 < board[h][w])
            {
                board[h][w] += std::min({ board[h - 1][w - 1], board[h - 1][w], board[h][w - 1] });
            }
            else if (0 == h)
            {
                if (0 < answer)
                {
                    break;
                }
            }
            answer = std::max(answer, board[h][w]);
        }
    }

    return answer * answer;
}

void FindingTheBiggestTriangleTest()
{
    std::vector<std::vector<int>> board = { {0,1,1,1} ,{1,1,1,1},{1,1,1,1},{0,0,1,0} }; // 9

    std::cout << "====================== Finding The Biggest Trianble Test Start ======================" << std::endl;

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

    auto res = solution3(board);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Finding The Biggest Trianble Test End ======================" << std::endl;
}
