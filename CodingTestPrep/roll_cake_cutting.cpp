
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <unordered_map>

static int solution1(std::vector<int> topping) {
    int answer = 0;

    std::unordered_map<int, int> younger, older;
    for (int i = 0; i < topping.size(); ++i)
    {
        older[topping[i]]++;
    }

    for (int i = 0; i < topping.size(); ++i)
    {
        older[topping[i]]--;
        if (0 == older[topping[i]])
        {
            older.erase(topping[i]);
        }
        younger[topping[i]]++;
        if (younger.size() == older.size())
        {
            answer++;
        }
    }

    return answer;
}

void RollCakeCuttingTest()
{
    //std::vector<int> toppings = { 1, 2, 1, 3, 1, 4, 1, 2 }; // 2
    std::vector<int> toppings = { 1, 2, 3, 1, 4 }; // 0

    std::cout << "====================== Roll Cake Cutting Test Start ======================" << std::endl;

    std::cout << "Toppings : [ ";
    for (const auto& ele : toppings)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(toppings);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Roll Cake Cutting Test End ======================" << std::endl;
}
