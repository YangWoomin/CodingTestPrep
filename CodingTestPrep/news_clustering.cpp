
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

static int solution1(std::string str1, std::string str2) {
    int answer = 0;

    int total = 0;
    std::unordered_map<std::string, int> count1;
    for (int i = 1; i < str1.size(); ++i)
    {
        char first = std::tolower(str1[i - 1]);
        char second = std::tolower(str1[i]);

        if ('a' <= first && 'z' >= first && 'a' <= second && 'z' >= second)
        {
            std::string token;
            token += first;
            token += second;

            count1[token]++;
            total++;
        }
    }

    int intersection = 0;
    for (int i = 1; i < str2.size(); ++i)
    {
        char first = std::tolower(str2[i - 1]);
        char second = std::tolower(str2[i]);

        if ('a' <= first && 'z' >= first && 'a' <= second && 'z' >= second)
        {
            std::string token;
            token += first;
            token += second;

            if (0 < count1[token])
            {
                intersection++;
            }
            else
            {
                total++;
            }
            count1[token]--;
        }
    }

    if (0 == total)
    {
        answer = 65536;
    }
    else
    {
        answer = intersection * 65536 / total;
    }

    return answer;
}

void NewsClusteringTest()
{
    //std::string str1 = "FRANCE";
    //std::string str2 = "french"; // 16384

    std::string str1 = "handshake";
    std::string str2 = "shake hands"; // 65536

    //std::string str1 = "aa1+aa2";
    //std::string str2 = "AAAA12"; // 43690

    //std::string str1 = "E=M*C^2";
    //std::string str2 = "e=m*c^2"; // 65536

    std::cout << "====================== News Clustering Test Start ======================" << std::endl;

    std::cout << "Str1 : " << str1 << std::endl;
    std::cout << "Str2 : " << str2 << std::endl;

    auto res = solution1(str1, str2);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== News Clustering Test End ======================" << std::endl;
}
