
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static std::string solution1(std::vector<int> numbers) {
    std::string answer = "";

    auto lesser = [&](int lhs, int rhs) {
        std::string l = std::to_string(lhs);
        std::string r = std::to_string(rhs);
        long long lr = std::stoll(l + r);
        long long rl = std::stoll(r + l);
        return lr < rl;
        };

    std::function<void(int, int)> heapify = [&](int idx, int size) {

        if (idx > size / 2 - 1)
        {
            return;
        }

        int* left = idx * 2 + 1 < size ? &numbers[idx * 2 + 1] : nullptr;
        int* right = idx * 2 + 2 < size ? &numbers[idx * 2 + 2] : nullptr;
        int* min = left;
        if (min && right)
        {
            if (!lesser(*min, *right))
            {
                min = right;
            }
        }
        if (min && !lesser(numbers[idx], *min))
        {
            std::swap(numbers[idx], *min);
            heapify(min == left ? idx * 2 + 1 : idx * 2 + 2, size);
        }
        };

    for (int i = numbers.size() / 2 - 1; i >= 0; --i)
    {
        heapify(i, numbers.size());
    }

    for (int i = numbers.size() - 1; i > 0; --i)
    {
        std::swap(numbers[0], numbers[i]);
        heapify(0, i);
    }

    bool isZero = true;
    for (const auto& ele : numbers)
    {
        if (0 != ele)
        {
            isZero = false;
        }
        answer += std::to_string(ele);
    }
    if (isZero)
    {
        answer = "0";
    }

    return answer;
}

static std::string solution2(std::vector<int> numbers) {
    std::string answer = "";

    std::vector<std::string> nums;
    for (const auto& ele : numbers)
    {
        nums.push_back(std::to_string(ele));
    }

    std::sort(nums.begin(), nums.end(), [](auto lhs, auto rhs) {
        return lhs + rhs > rhs + lhs;
        });

    if ("0" == nums[0])
    {
        answer = "0";
    }
    else
    {
        for (const auto& ele : nums)
        {
            answer += ele;
        }
    }

    return answer;
}

void TheBiggestNumberTest()
{
    //std::vector<int> numbers = { 6, 10, 2 }; // "6210"
    std::vector<int> numbers = { 3, 30, 34, 5, 9 }; // "9534330"

    std::cout << "====================== The Biggest Number Test Start ======================" << std::endl;

    std::cout << "Numbers : [ ";
    for (const auto& ele : numbers)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(numbers);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== The Biggest Number Test End ======================" << std::endl;
}
