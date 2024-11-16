
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static int solution1(int m, int n, std::vector<std::string> board) {
    int answer = 0;

    const std::vector<int> hOffset = { 0, -1, -1 };
    const std::vector<int> wOffset = { -1, -1, 0 };

    while (true)
    {
        std::vector<std::pair<int, int>> blocks;

        for (int h = m - 1; h > 0; --h)
        {
            for (int w = 1; w < n; ++w)
            {
                char friends = board[h][w];
                if ('-' == friends)
                {
                    continue;
                }

                bool same = true;
                for (int i = 0; i < 3; ++i)
                {
                    int tmpH = h + hOffset[i];
                    int tmpW = w + wOffset[i];
                    if (friends != board[tmpH][tmpW])
                    {
                        same = false;
                        break;
                    }
                }

                if (same)
                {
                    blocks.push_back({ h, w });
                }
            }
        }

        if (blocks.empty())
        {
            break;
        }

        for (const auto& [h, w] : blocks)
        {
            if ('-' != board[h][w])
            {
                answer++;
            }
            board[h][w] = '-';

            for (int i = 0; i < 3; ++i)
            {
                int tmpH = h + hOffset[i];
                int tmpW = w + wOffset[i];
                if ('-' != board[tmpH][tmpW])
                {
                    answer++;
                }
                board[tmpH][tmpW] = '-';
            }
        }

        for (int w = 0; w < n; ++w)
        {
            for (int h = m - 1; h > 0; --h)
            {
                if ('-' != board[h][w])
                {
                    continue;
                }

                int idx = m;
                for (int i = h - 1; i >= 0; --i)
                {
                    if ('-' != board[i][w])
                    {
                        idx = i;
                        break;
                    }
                }
                if (idx == m)
                {
                    break;
                }

                for (int i = h; i >= 0 && idx >= 0; --i, --idx)
                {
                    std::swap(board[i][w], board[idx][w]);
                }
            }
        }
    }

    return answer;
}

void FriendsBlockTest()
{
    //int m = 4, n = 5;
    //std::vector<std::string> board = {
    //    "CCBDE", 
    //    "AAADE", 
    //    "AAABF", 
    //    "CCBBF"
    //}; // 14

    int m = 6, n = 6;
    std::vector<std::string> board = {
        "TTTANT", 
        "RRFACC", 
        "RRRFCC", 
        "TRRRAA", 
        "TTMMMF", 
        "TMMTTJ"
    }; // 15

    std::cout << "====================== Friends Block Test Start ======================" << std::endl;

    std::cout << "M : " << m << ", N : " << n << std::endl;
    std::cout << "Board : " << std::endl;
    for (const auto& ele : board)
    {
        std::cout << ele << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(m, n, board);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Friends Block Test End ======================" << std::endl;
}
