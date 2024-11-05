
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

static std::string solution1(std::string s) {

    for (int i = 0; i < s.size(); ++i)
    {
        if ('a' <= s[i] && 'z' >= s[i])
        {
            if (0 == i || ' ' == s[i - 1])
            {
                s[i] += 'A' - 'a';
            }
        }
        else if ('A' <= s[i] && 'Z' >= s[i])
        {
            if (0 != i && ' ' != s[i - 1])
            {
                s[i] += 'a' - 'A';
            }
        }
    }

    return s;
}

void JadenCaseTest()
{
    //std::string s = "3people unFollowed me"; // "3people Unfollowed Me"
    std::string s = "for the last week"; // "For The Last Week"

    std::cout << "====================== Jaden Case Test Start ======================" << std::endl;

    std::cout << "S : " << s << std::endl;

    auto res = solution1(s);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Jaden Case Test End ======================" << std::endl;
}
