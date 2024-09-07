
#include	"stack_test.h"

#include	<iostream>
#include	<string>

static bool solution1(std::string s)
{
    int counter = 0;

    for (const auto& ele : s)
    {
        if ('(' == ele)
        {
            counter++;
        }
        else
        {
            if (0 == counter)
            {
                return false;
            }
            counter--;
        }
    }

    return counter == 0;
}

void CorrectBracketTest()
{
    //std::string s = "()()"; // true
    //std::string s = "(())()"; // true
    //std::string s = ")()("; // false
    std::string s = "(()("; // false

    std::cout << "====================== Corret Bracket Test Start ======================" << std::endl;

    std::cout << "Bracket : " << s << std::endl;

    bool res = solution1(s);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Corret Bracket Test End ======================" << std::endl;
}
