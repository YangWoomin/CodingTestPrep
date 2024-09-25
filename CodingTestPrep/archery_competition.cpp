
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>

static std::vector<int> solution1(int n, std::vector<int> info) {
    std::vector<std::vector<int>> answers;
    int ryan = 0, apeach = 0;

    for (int i = 0; i < info.size(); ++i)
    {
        if (0 < info[i])
        {
            apeach += 10 - i;
        }
    }

    std::vector<int> counts(11, 0);
    std::function<void(int, int, int)> dfs = [&](int idx, int rest, int sum) {

        if (0 == rest)
        {
            if (ryan <= sum)
            {
                if (ryan < sum)
                {
                    answers.clear();
                }
                ryan = sum;
                answers.push_back(counts);
            }
            return;
        }

        int promising = (10 - idx) * (11 - idx) / 2 * 2;
        if (0 < 10 - idx - rest)
        {
            promising -= (10 - idx - rest) * (11 - idx - rest) / 2 * 2;
        }
        if (sum + promising <= apeach || sum + promising < ryan)
        {
            return;
        }

        if (10 > idx && 0 < rest - info[idx])
        {
            counts[idx] = info[idx] + 1;
            int tmp = 1 < counts[idx] ? sum + (10 - idx) * 2 : sum + (10 - idx);
            dfs(idx + 1, rest - counts[idx], tmp);
        }

        if (10 == idx)
        {
            counts[idx] = rest;
        }
        else
        {
            counts[idx] = 0;
        }
        dfs(idx + 1, rest - counts[idx], sum);
        counts[idx] = 0;
        };

    dfs(0, n, 0);

    if (apeach >= ryan)
    {
        return { -1 };
    }
    else
    {
        int answer = 0, max1 = 0, max2 = 0;
        for (int i = 0; i < answers.size(); ++i)
        {
            for (int j = answers[i].size() - 1; j >= 0; --j)
            {
                if (0 < answers[i][j])
                {
                    if (max1 < j || (max1 == j && max2 < answers[i][j]))
                    {
                        answer = i;
                        max1 = j;
                        max2 = answers[i][j];
                        break;
                    }
                }
            }
        }
        return answers[answer];
    }
}

void ArcheryCompetitionTest()
{
    //int n = 5;
    //std::vector<int> info = { 2,1,1,1,0,0,0,0,0,0,0 }; // [0,2,2,0,1,0,0,0,0,0,0]

    //int n = 1;
    //std::vector<int> info = { 1,0,0,0,0,0,0,0,0,0,0 }; // [-1]

    //int n = 9;
    //std::vector<int> info = { 0,0,1,2,0,1,1,1,1,1,1 }; // [1,1,2,0,1,2,2,0,0,0,0]

    int n = 10;
    std::vector<int> info = { 0,0,0,0,0,0,0,0,3,4,3 }; // [1,1,1,1,1,1,1,1,0,0,2]

    std::cout << "====================== Archery Competition Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;
    std::cout << "Info : [ ";
    for (const auto& ele : info)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, info);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Archery Competition Test Start ======================" << std::endl;
}
