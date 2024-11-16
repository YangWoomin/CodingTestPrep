
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>
#include    <map>

static int solution1(int cacheSize, std::vector<std::string> cities) {
    int answer = 0;

    int age = 0;
    std::unordered_map<std::string, int> cache;
    std::map<int, std::string> lru;

    for (auto& city : cities)
    {
        std::transform(city.begin(), city.end(), city.begin(), [](unsigned char c) {
            return std::tolower(c);
            });

        if (cache.end() == cache.find(city))
        {
            answer += 5;
            cache[city] = ++age;
            lru[age] = city;
        }
        else
        {
            answer += 1;
            int _age = cache[city];
            lru.erase(_age);
            cache[city] = ++age;
            lru.insert({ age, city });
        }

        if (cacheSize < cache.size())
        {
            auto [_age, _city] = *lru.begin();
            lru.erase(lru.begin());
            cache.erase(_city);
        }
    }

    return answer;
}

void CacheTest()
{
    //int cacheSize = 3;
    //std::vector<std::string> cities = {
    //    "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"
    //}; // 50

    //int cacheSize = 3;
    //std::vector<std::string> cities = {
    //    "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"
    //}; // 21

    int cacheSize = 0;
    std::vector<std::string> cities = {
        "Jeju", "Pangyo", "Seoul", "NewYork", "LA"
    }; // 25

    std::cout << "====================== Cache Test Start ======================" << std::endl;

    std::cout << "Cache Size : " << cacheSize << std::endl;
    std::cout << "Cities : [ ";
    for (const auto& ele : cities)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(cacheSize, cities);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Cache Test End ======================" << std::endl;
}
