
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

static std::vector<int> solution1(std::vector<std::string> keyinput, std::vector<int> board) {
    std::vector<int> answer = { 0, 0 };

    std::unordered_map<std::string, std::pair<int, int>> dir;
    dir["up"] = { 0, 1 };
    dir["down"] = { 0, -1 };
    dir["left"] = { -1, 0 };
    dir["right"] = { 1, 0 };

    auto isValid = [&](int x, int y) {
        int maxX = board[0] / 2;
        int minX = board[0] / 2 * -1;
        int maxY = board[1] / 2;
        int minY = board[1] / 2 * -1;
        return maxX >= x && minX <= x && maxY >= y && minY <= y;
        };

    for (const auto& ele : keyinput)
    {
        if (isValid(answer[0] + dir[ele].first, answer[1] + dir[ele].second))
        {
            answer[0] += dir[ele].first;
            answer[1] += dir[ele].second;
        }
    }

    return answer;
}

void CharacterCoordinateTest()
{
    //std::vector<std::string> keyinput = { "left", "right", "up", "right", "right" };
    //std::vector<int> board = { 11, 11 }; // [2, 1]

    std::vector<std::string> keyinput = { "down", "down", "down", "down", "down" };
    std::vector<int> board = { 7, 9 }; // [0, -4]

    std::cout << "====================== Character Coordinate Test Start ======================" << std::endl;

    std::cout << "Key Input : [ ";
    for (const auto& ele : keyinput)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Board : [ " << board[0] << " " << board[1] << " ]" << std::endl;

    auto res = solution1(keyinput, board);
    std::cout << "Result : [ " << res[0] << " " << res[1] << " ]" << std::endl;

    std::cout << "====================== Character Coordinate Test End ======================" << std::endl;
}
