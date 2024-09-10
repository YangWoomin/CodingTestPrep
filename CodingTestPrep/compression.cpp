
#include	"hash_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_map>

static std::vector<int> solution1(std::string msg) {
    std::vector<int> answer;

    std::unordered_map<std::string, int> dict;
    for (char ch = 'A'; ch <= 'Z'; ++ch)
    {
        std::string key;
        key += ch;
        dict[key] = ch - 'A' + 1;
    }

    int idx = dict.size();
    for (int i = 0; i < msg.size(); ++i)
    {
        for (int j = i + 1; j <= msg.size(); ++j)
        {
            std::string next = msg.substr(i, j - i);
            if (dict.end() == dict.find(next))
            {
                dict[next] = ++idx;
                next = next.substr(0, next.size() - 1);
                answer.push_back(dict[next]);
                i = j - 2;
                break;
            }
            if (j == msg.size())
            {
                i = j - 1;
                answer.push_back(dict[next]);
            }
        }
    }

    return answer;
}

void CompressionTest()
{
    //std::string msg = "KAKAO"; // [11, 1, 27, 15]
    std::string msg = "TOBEORNOTTOBEORTOBEORNOT"; // [20, 15, 2, 5, 15, 18, 14, 15, 20, 27, 29, 31, 36, 30, 32, 34]
    //std::string msg = "ABABABABABABABAB"; // [1, 2, 27, 29, 28, 31, 30]

    std::cout << "====================== Compression Test Start ======================" << std::endl;

    std::cout << "Message : " << msg << std::endl;

    auto res = solution1(msg);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Compression Test End ======================" << std::endl;
}

