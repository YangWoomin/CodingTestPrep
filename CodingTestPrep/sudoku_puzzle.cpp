
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <unordered_set>

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> input_board)
{
    auto getBoxSetIdx = [&](int y, int x) {
        return (y / 3) * 3 + x / 3;
    };

    std::vector<std::unordered_set<int>> rowSet(9);
    std::vector<std::unordered_set<int>> colSet(9);
    std::vector<std::unordered_set<int>> boxSet(9);
    std::vector<std::pair<int, int>> blanks;
    for (int y = 0; y < input_board.size(); ++y)
    {
        for (int x = 0; x < input_board[y].size(); ++x)
        {
            if (0 != input_board[y][x])
            {
                rowSet[y].insert(input_board[y][x]);
                colSet[x].insert(input_board[y][x]);
                boxSet[getBoxSetIdx(y, x)].insert(input_board[y][x]);
            }
            else
            {
                blanks.push_back({ y, x });
            }
        }
    }

    std::function<bool(int)> dfs = [&](int idx) {
        if (blanks.size() == idx)
        {
            return true; // all done
        }

        auto& [y, x] = blanks[idx];
        for (int i = 1; i <= 9; ++i)
        {
            if (rowSet[y].end() == rowSet[y].find(i)
                && colSet[x].end() == colSet[x].find(i)
                && boxSet[getBoxSetIdx(y, x)].end() == boxSet[getBoxSetIdx(y, x)].find(i))
            {
                rowSet[y].insert(i);
                colSet[x].insert(i);
                boxSet[getBoxSetIdx(y, x)].insert(i);
                input_board[y][x] = i;

                if (true == dfs(idx + 1))
                {
                    return true;
                }

                rowSet[y].erase(i);
                colSet[x].erase(i);
                boxSet[getBoxSetIdx(y, x)].erase(i);
                input_board[y][x] = 0;
            }
        }

        return false;
    };

    dfs(0);

    return input_board;
}

void SudokuPuzzleTest()
{
    std::vector<std::vector<int>> input_board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    /*
        [ 5 3 4 6 7 8 9 1 2 ]
        [ 6 7 2 1 9 5 3 4 8 ]
        [ 1 9 8 3 4 2 5 6 7 ]
        [ 8 5 9 7 6 1 4 2 3 ]
        [ 4 2 6 8 5 3 7 9 1 ]
        [ 7 1 3 9 2 4 8 5 6 ]
        [ 9 6 1 5 3 7 2 8 4 ]
        [ 2 8 7 4 1 9 6 3 5 ]
        [ 3 4 5 2 8 6 1 7 9 ]
    */

    std::cout << "====================== Sudoku Puzzle Test Start ======================" << std::endl;

    std::cout << "Input Board : " << std::endl;
    for (const auto& ele : input_board)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;;
    }
    std::cout << std::endl;

    auto res = solution1(input_board);
    std::cout << "Result : " << std::endl;
    for (const auto& ele : res)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====================== Sudoku Puzzle Test Start ======================" << std::endl;
}
