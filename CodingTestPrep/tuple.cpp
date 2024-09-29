
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static std::vector<int> solution1(std::string s) {
    std::vector<int> answer;

    std::vector<std::pair<int, int>> nums(100001, { 0, 0 });

    std::string tmp;
    for (const auto& ele : s)
    {
        if (48 <= ele && 57 >= ele)
        {
            tmp += ele;
            continue;
        }
        else if (0 < tmp.size())
        {
            int num = std::atoi(tmp.c_str());
            nums[num] = { nums[num].first + 1, num };
            tmp.clear();
        }
    }

    std::sort(nums.begin(), nums.end(), [](auto& lhs, auto& rhs) {
        return lhs.first > rhs.first;
        });

    for (const auto& [freq, num] : nums)
    {
        if (num)
        {
            answer.push_back(num);
        }
    }

    return answer;
}

void TupleTest()
{
    //std::string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}"; // [2, 1, 3, 4]
    //std::string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}"; // [2, 1, 3, 4]
    //std::string s = "{{20,111},{111}}"; // [111, 20]
    //std::string s = "{{123}}"; // [123]
    std::string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"; // [3, 2, 4, 1]

    std::cout << "====================== Tuple Test Start ======================" << std::endl;

    std::cout << "s : " << s << std::endl;

    auto res = solution1(s);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Tuple Test End ======================" << std::endl;
}
