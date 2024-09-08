
#include	"queue_test.h"

#include    <iostream>
#include    <string>
#include    <vector>
#include    <unordered_map>
#include    <algorithm>

static std::vector<int> solution1(std::vector<std::string> genres, std::vector<int> plays) {
    std::vector<int> answer;

    std::unordered_map<std::string, int> genreCount;
    std::unordered_map<std::string, std::pair<int, int>> candidates;

    for (int i = 0; i < genres.size(); ++i)
    {
        genreCount[genres[i]] += plays[i];

        auto res = candidates.insert(std::make_pair(genres[i], std::make_pair(i, -1)));
        if (false == res.second)
        {
            if (plays[res.first->second.first] < plays[i])
            {
                res.first->second.second = res.first->second.first;
                res.first->second.first = i;
            }
            else if (-1 == res.first->second.second || plays[res.first->second.second] < plays[i])
            {
                res.first->second.second = i;
            }
        }
    }

    std::vector<std::pair<std::string, int>> sorted;
    for (const auto& ele : genreCount)
    {
        sorted.push_back(std::make_pair(ele.first, ele.second));
    }
    std::sort(sorted.begin(), sorted.end(), [](auto lhs, auto rhs) {
        return lhs.second > rhs.second;
        });

    for (const auto& ele : sorted)
    {
        auto finder = candidates.find(ele.first);
        answer.push_back(finder->second.first);
        if (-1 != finder->second.second)
        {
            answer.push_back(finder->second.second);
        }
    }

    return answer;
}

void BestAlbumTest()
{
    std::vector<std::string> genres = { "classic", "pop", "classic", "classic", "pop" }; // [ 4 1 3 0 ]
    std::vector<int> plays = { 500, 600, 150, 800, 2500 };

    std::cout << "====================== Best Album Test Start ======================" << std::endl;

    std::cout << "Genres : [ ";
    for (const auto& ele : genres)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    auto res = solution1(genres, plays);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Best Album Test End ======================" << std::endl;
}
