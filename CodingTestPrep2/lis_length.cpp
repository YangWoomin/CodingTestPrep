
#include	"dp_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<functional>

static int solution1(std::vector<int> nums)
{
    int answer = 0;

    std::vector<int> dp(nums.size());
    
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = std::max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;

        answer = std::max(answer, dp[i]);
    }

    return answer;
}

void LisLengthTest()
{
    std::vector<int> nums = { 1, 4, 2, 3, 1, 5, 7, 3 }; // 5
    //std::vector<int> nums = { 3, 2, 1 }; // 1

    std::cout << "Numbers : [ ";
    for (const auto& ele : nums)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(nums);

    std::cout << "Result : " << res << std::endl;
}
