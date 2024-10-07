
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

#include    <queue>

// dp (time over)
static std::string solution1(std::string number, int k) {

    const int size = number.size();

    std::vector<std::string> dp(k + 1);

    std::string cur;
    for (int i = 1; i <= size; ++i)
    {
        cur += number[i - 1];

        for (int j = k < cur.size() - 1 ? k : cur.size() - 1; j > 0; --j)
        {
            dp[j] = std::max(dp[j - 1], dp[j] + number[i - 1]);
        }

        dp[0] = cur;
    }

    return dp[k];
}

// greedy
static std::string solution2(std::string number, int k) {
    std::string answer = "";

    std::deque<char> dq;

    for (int i = 0; i < number.size(); ++i)
    {
        while (!dq.empty() && 0 < k)
        {
            char pre = dq.back();
            if (pre < number[i])
            {
                dq.pop_back();
                k--;
            }
            else
            {
                break;
            }
        }
        dq.push_back(number[i]);
    }

    while (0 < k)
    {
        dq.pop_back();
        k--;
    }

    while (!dq.empty())
    {
        char pre = dq.front();
        dq.pop_front();

        answer += pre;
    }

    return answer;
}

void MakingBigNumberTest()
{
    //std::string number = "1924";
    //int k = 2; // "94"

    //std::string number = "1231234";
    //int k = 3; // "3234"

    std::string number = "4177252841";
    int k = 4; // "775841"

    std::cout << "====================== Making Big Number Test Start ======================" << std::endl;

    std::cout << "Number : " << number << ", K : " << k << std::endl;

    auto res = solution2(number, k);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Making Big Number Test End ======================" << std::endl;
}
