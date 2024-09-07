
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include    <string>

static std::string solution1(std::vector<std::string> cards1, std::vector<std::string> cards2, std::vector<std::string> goal) {
    int idx1 = 0, idx2 = 0;
    for (const auto& ele : goal)
    {
        if (cards1.size() > idx1 && ele == cards1[idx1])
        {
            idx1++;
            continue;
        }
        if (cards2.size() > idx2 && ele == cards2[idx2])
        {
            idx2++;
            continue;
        }

        return "No";
    }

    return "Yes";
}

void CardBundleTest()
{
    //std::vector<std::string> cards1 = { "i", "drink", "water" };
    //std::vector<std::string> cards2 = { "want", "to" };
    //std::vector<std::string> goal = { "i", "want", "to", "drink", "water" }; // Yes

    std::vector<std::string> cards1 = { "i", "water", "drink" };
    std::vector<std::string> cards2 = { "want", "to" };
    std::vector<std::string> goal = { "i", "want", "to", "drink", "water" }; // No

    std::cout << "====================== Card Bundle Test Start ======================" << std::endl;

    std::cout << "Cards 1 : [ ";
    for (const auto& ele : cards1)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    std::cout << "Cards 2 : [ ";
    for (const auto& ele : cards1)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    auto res = solution1(cards1, cards2, goal);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Card Bundle Test End ======================" << std::endl;
}
