
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

// permutation
static int solution1(std::vector<int> numbers, int target) {
    int answer = 0;

    const int size = numbers.size();
    for (int i = 0; i <= size; ++i)
    {
        std::vector<int> sel(size, 1);
        for (int j = 0; j < i; ++j)
        {
            sel[j] = 0;
        }

        do
        {
            int sum = 0;
            for (int j = 0; j < sel.size(); ++j)
            {
                if (1 == sel[j])
                {
                    sum -= numbers[j];
                }
                else
                {
                    sum += numbers[j];
                }
            }
            if (target == sum)
            {
                answer++;
            }
        } while (std::next_permutation(sel.begin(), sel.end()));
    }

    return answer;
}

// dfs
static int solution2(std::vector<int> numbers, int target) {
    int answer = 0;

    std::function<void(int, int)> dfs = [&](int idx, int sum) {
        if (numbers.size() == idx)
        {
            if (target == sum)
            {
                answer++;
            }
            return;
        }

        dfs(idx + 1, sum + numbers[idx]);
        dfs(idx + 1, sum - numbers[idx]);
        };

    dfs(0, 0);

    return answer;
}

void TargetNumberTest()
{
    std::vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target= 3; // 5

    //std::vector<int> numbers = { 4, 1, 2, 1 };
    //int target = 4; // 2

    std::cout << "====================== Target Number Test Start ======================" << std::endl;

    std::cout << "Numbers : [ ";
    for (const auto& ele : numbers)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(numbers, target);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Target Number Test End ======================" << std::endl;
}
