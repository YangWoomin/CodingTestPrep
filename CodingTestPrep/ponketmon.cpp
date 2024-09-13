
#include	"set_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <unordered_set>

static int solution1(std::vector<int> nums)
{
    const int size = nums.size();

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    return nums.size() < size / 2 ? nums.size() : size / 2;
}

static int solution2(std::vector<int> nums)
{
    std::unordered_set<int> set(nums.begin(), nums.end());

    return std::min(set.size(), nums.size() / 2);
}

void PonketmonTest()
{
    //std::vector<int> nums = { 3,1,2,3 }; // 2
    std::vector<int> nums = { 3,3,3,2,2,4 }; // 3
    //std::vector<int> nums = { 3,3,3,2,2,2 }; // 2

    std::cout << "====================== Ponketmon Test Start ======================" << std::endl;

    std::cout << "Numbers : [ ";
    for (const auto& ele : nums)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(nums);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Ponketmon Test End ======================" << std::endl;
}

