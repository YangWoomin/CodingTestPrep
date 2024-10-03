
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

// binary search
static int solution1(std::vector<int> nums)
{
    std::vector<int> lis;

    for (const auto& ele : nums)
    {
        auto it = std::lower_bound(lis.begin(), lis.end(), ele);
        if (lis.end() == it)
        {
            lis.push_back(ele);
        }
        else
        {
            *it = ele;
        }
    }

    return lis.size();
}

// exhaustive search
static int solution2(std::vector<int> nums)
{
    std::vector<int> dp(nums.size(), 1);
    int max = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[j] < nums[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                if (max < dp[i])
                {
                    max = dp[i];
                }
            }
        }
    }

    return max;
}

void LisLengthTest()
{
    //std::vector<int> nums = { 1, 4, 2, 3, 1, 5, 7, 3 }; // 5
    std::vector<int> nums = { 3, 2, 1 }; // 1

    std::cout << "====================== LIS Length Test Start ======================" << std::endl;

    std::cout << "Numbers : [ ";
    for (const auto& ele : nums)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(nums);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== LIS Length Test End ======================" << std::endl;
}
