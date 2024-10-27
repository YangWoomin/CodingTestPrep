
#include	"test2.h"

#include	<iostream>
#include	<vector>
#include	<stack>
#include    <string>

#include    <unordered_set>

static int solution1(std::vector<int> numbers) {
    int answer = 0;

    std::unordered_set<int> set(numbers.begin(), numbers.end());

    for (int i = 0; i < 10; ++i)
    {
        if (set.end() == set.find(i))
        {
            answer += i;
        }
    }

    return answer;
}

void AbsentNumberAdditionTest()
{
    //std::vector<int> numbers = { 1,2,3,4,6,7,8,0 }; // 14
    std::vector<int> numbers = { 5,8,4,0,6,7,9 }; // 6

    std::cout << "====================== Absent Number Addition Test Start ======================" << std::endl;

    std::cout << "Numbers : [ ";
    for (const auto& ele : numbers)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(numbers);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Absent Number Addition Test End ======================" << std::endl;
}
