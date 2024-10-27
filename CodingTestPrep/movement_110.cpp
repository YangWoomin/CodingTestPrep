
#include	"test2.h"

#include	<iostream>
#include	<vector>
#include	<stack>
#include    <string>

#include    <unordered_map>

static std::vector<std::string> solution1(std::vector<std::string> s) {
    std::vector<std::string> answer;

    for (const auto& ele : s)
    {
        std::string str;
        int count = 0;
        for (int i = 0; i < ele.size(); ++i)
        {
            str += ele[i];
            if (3 <= str.size() && str.substr(str.size() - 3, 3) == "110")
            {
                str.erase(str.size() - 3, 3);
                count++;
            }
        }

        std::string _110s;
        for (int i = 0; i < count; ++i)
        {
            _110s += "110";
        }

        std::string ans;
        bool found = false;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str.substr(i, 2) == "11")
            {
                ans = str.substr(0, i);
                ans += _110s;
                ans += str.substr(i);
                found = true;
                break;
            }
        }

        if (!found)
        {
            for (int i = str.size() - 1; i >= 0; --i)
            {
                if ('0' == str[i])
                {
                    ans = str.substr(0, i + 1);
                    ans += _110s;
                    ans += str.substr(i + 1);
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            ans = _110s + str;
        }

        //std::cout << str << "-" << ans << " ";

        answer.push_back(ans);
    }

    return answer;
}

void Movement110Test()
{
    std::vector<std::string> s = { "1110","100111100","0111111010" }; // ["1101","100110110","0110110111"]

    std::cout << "====================== Movement 110 Test Start ======================" << std::endl;

    std::cout << "Strings : [ ";
    for (const auto& ele : s)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(s);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Movement 110 Test End ======================" << std::endl;
}
