
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static int solution1(std::vector<int> arr) {
    int answer = 0;

    std::sort(arr.begin(), arr.end());

    int unit = arr.back();
    arr.pop_back();

    answer = unit;

    while (true)
    {
        bool success = true;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (0 != answer % arr[i])
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            return answer;
        }
        answer += unit;
    }

    return answer;
}

void NLeastCommonMultipleTest()
{
    //std::vector<int> arr = { 2, 6, 8, 14 }; // 168
    std::vector<int> arr = { 1, 2, 3 }; // 6

    std::cout << "====================== N Least Common Multiple Test Start ======================" << std::endl;

    std::cout << "Array  : [ ";
    for (const auto& ele : arr)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(arr);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== N Least Common Multiple Test End ======================" << std::endl;
}
