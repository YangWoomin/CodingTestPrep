
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <cmath>

static int solution1(int n, std::vector<std::string> data) {
    int answer = 0;

    std::vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

    do
    {
        bool satisfied = true;

        for (const auto& ele : data)
        {
            char one = ele[0];
            char other = ele[2];
            char intention = ele[3];
            int offset = std::stoi(ele.substr(4)) + 1;

            int idx1 = 0, idx2 = 0;
            for (int i = 0; i < friends.size(); ++i)
            {
                if (friends[i] == one)
                {
                    idx1 = i;
                }
                if (friends[i] == other)
                {
                    idx2 = i;
                }
            }

            if ('=' == intention)
            {
                if (std::abs(idx1 - idx2) != offset)
                {
                    satisfied = false;
                    break;
                }
            }
            else if ('>' == intention)
            {
                if (std::abs(idx1 - idx2) <= offset)
                {
                    satisfied = false;
                    break;
                }
            }
            else if ('<' == intention)
            {
                if (std::abs(idx1 - idx2) >= offset)
                {
                    satisfied = false;
                    break;
                }
            }
        }

        if (satisfied)
        {
            answer++;
        }
    } while (std::next_permutation(friends.begin(), friends.end()));

    return answer;
}

void TakingGroupPhotoTest()
{
    int n = 2;
    std::vector<std::string> data = {
        "N~F=0", 
        "R~T>2"
    }; // 3648

    //int n = 2;
    //std::vector<std::string> data = {
    //    "M~C<2", 
    //    "C~M>1"
    //}; // 0

    std::cout << "====================== Taking Group Photo Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;
    std::cout << "Data : " << std::endl;
    for (const auto& ele : data)
    {
        std::cout << ele << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(n, data);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Taking Group Photo Test End ======================" << std::endl;
}
