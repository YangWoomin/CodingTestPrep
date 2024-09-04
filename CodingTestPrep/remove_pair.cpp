
#include	"stack_test.h"

#include	<iostream>
#include	<string>
#include	<stack>

static bool solution1(std::string& s)
{
    std::stack<char> tmp;

    for (const auto& ele : s)
    {
        if (true == tmp.empty())
        {
            tmp.push(ele);
            continue;
        }

        char last = tmp.top();
        if (last == ele)
        {
            tmp.pop();
        }
        else
        {
            tmp.push(ele);
        }
    }

    return tmp.empty();
}

void RemovePairTest()
{
    //std::string s = "baabaa";
    std::string s = "cdcd";

    std::cout << "====================== Remove Pair Test Start ======================" << std::endl;

    std::cout << "String : " << s << std::endl;

    bool res = solution1(s);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Remove Pair Test End ======================" << std::endl;
}
