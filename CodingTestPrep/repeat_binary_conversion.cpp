
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

#include    <bitset>

static std::vector<int> solution1(std::string s) {
    std::vector<int> answer = { 0, 0 };

    int count = std::count(s.begin(), s.end(), '1');
    answer[0] += 1;
    answer[1] += s.size() - count;
    while (1 < count)
    {
        int tmp = 0;
        while (0 < count)
        {
            if (count % 2)
            {
                tmp++;
            }
            else
            {
                answer[1]++;
            }
            count /= 2;
        }
        count = tmp;
        answer[0]++;
    }

    return answer;
}

static std::vector<int> solution2(std::string s) {

    int count = 0, zeros = 0;
    std::bitset<32> bs;

    while ("1" != s)
    {
        int tmp = std::count(s.begin(), s.end(), '1');
        zeros += s.size() - tmp;

        s = std::bitset<32>(tmp).to_string();
        s = s.substr(s.find('1'));
        count++;
    }

    return { count, zeros };
}

void RepeatBinaryConversionTest()
{
    std::string s = "110010101001"; // [3, 8]
    //std::string s = "01110"; // [3, 3]
    //std::string s = "1111111"; // [4, 1]

    std::cout << "====================== Repeat Binary Conversion Test Start ======================" << std::endl;

    std::cout << "S : " << s << std::endl;

    auto res = solution2(s);
    std::cout << "Result : [ " << res[0] << ", " << res[1] << " ]" << std::endl;

    std::cout << "====================== Repeat Binary Conversion Test End ======================" << std::endl;
}
