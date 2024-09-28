
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>

static std::vector<std::vector<int>> solution1(int N)
{
    std::vector<std::vector<int>> res;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        arr[i] = i + 1;
    }

    std::function<void(int, int, std::vector<int>&)> dfs = [&](int idx, int sum, std::vector<int>& answer) {
        
        if (10 == sum)
        {
            res.push_back(answer);
            return;
        }
        else if (10 < sum)
        {
            return;
        }
        else if (N <= idx)
        {
            return;
        }

        dfs(idx + 1, sum, answer);

        answer.push_back(arr[idx]);
        dfs(idx + 1, sum + arr[idx], answer);
        answer.pop_back();
    };

    std::vector<int> answer;
    dfs(0, 0, answer);

    return res;
}

void SumCombinationFor10Test()
{
    //int N = 5; // [ [ 2 3 5 ] [ 1 4 5 ] [ 1 2 3 4 ] ]
    //int N = 2; // [ ]
    int N = 7; // [ [ 4 6 ] [ 3 7 ] [ 2 3 5 ] [ 1 4 5 ] [ 1 3 6 ] [ 1 2 7 ] [ 1 2 3 4 ] ]

    std::cout << "====================== Sum Combination For 10 Test Start ======================" << std::endl;

    std::cout << "N : " << N << std::endl;

    auto res = solution1(N);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Sum Combination For 10 Test End ======================" << std::endl;
}
