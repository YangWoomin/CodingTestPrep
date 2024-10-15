
#include	"backtracking_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>
#include	<unordered_set>

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> board)
{
	const int size = 9;
	std::vector<std::unordered_set<int>> rows(size);
	std::vector<std::unordered_set<int>> cols(size);
	std::vector<std::unordered_set<int>> boxes(size);
	std::vector<int> targets;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i][j])
			{
				rows[i].insert(board[i][j]);
				cols[j].insert(board[i][j]);
				boxes[i / 3 * 3 + j / 3].insert(board[i][j]);
			}
			else
			{
				targets.push_back(size * i + j);
			}
		}
	}

	std::function<bool(int)> dfs = [&](int idx) {

		if (targets.size() <= idx)
		{
			return true;
		}

		for (int i = 1; i <= 9; ++i)
		{
			int row = targets[idx] / size;
			int col = targets[idx] % size;
			int box = row / 3 * 3 + col / 3;

			if (rows[row].end() == rows[row].find(i)
				&& cols[col].end() == cols[col].find(i)
				&& boxes[box].end() == boxes[box].find(i))
			{
				rows[row].insert(i);
				cols[col].insert(i);
				boxes[box].insert(i);
				board[row][col] = i;
				bool res = dfs(idx + 1);
				if (res)
				{
					return true;
				}
				rows[row].erase(i);
				cols[col].erase(i);
				boxes[box].erase(i);
			}
		}

		return false;
	};
	
	dfs(0);

	return board;
}

void SudokuTest()
{
	std::vector<std::vector<int>> board = { 
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

	auto res = solution1(board);

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
}
