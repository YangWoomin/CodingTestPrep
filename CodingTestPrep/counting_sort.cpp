
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>

static std::string solution1(std::string s)
{
    std::vector<int> freq(26, 0);

    for (const auto& ele : s)
    {
        freq[ele - 'a']++;
    }

    std::string res;
    
    for (int i = 0; i < freq.size(); ++i)
    {
        for (int j = 0; j < freq[i]; ++j)
        {
            res += i + 'a';
        }
    }

    return res;
}

void CountingSortTest()
{
	//std::string s = "hello"; // "ehllo"
    std::string s = "algorithm"; // "aghilmort"

    std::cout << "====================== Counting Sort Test Start ======================" << std::endl;

    std::cout << "Str : " << s << std::endl;

    auto res = solution1(s);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Counting Sort Test Start ======================" << std::endl;
}
