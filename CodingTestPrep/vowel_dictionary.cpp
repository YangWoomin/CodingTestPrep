
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static int solution1(std::string word) {
    int answer = 0;

    std::string vowel = "AEIOU";

    std::function<bool(int, std::string)> dfs = [&](int idx, std::string str) {

        if (5 == idx)
        {
            return false;
        }

        for (const auto& ele : vowel)
        {
            answer++;
            if (str + ele == word)
            {
                return true;
            }

            if (dfs(idx + 1, str + ele))
            {
                return true;
            }
        }

        return false;
        };

    dfs(0, "");

    return answer;
}

void VowelDictionaryTest()
{
    //std::string word = "AAAAE"; // 6
    //std::string word = "AAAE"; // 10
    //std::string word = "I"; // 1563
    std::string word = "EIO"; // 1189

    std::cout << "====================== Vowel Dictionary Test Start ======================" << std::endl;

    std::cout << "Word : " << word << std::endl;
    
    auto res = solution1(word);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Vowel Dictionary Test Start ======================" << std::endl;
}
