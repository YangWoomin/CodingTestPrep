
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>
#include    <unordered_set>
#include    <functional>

static int solution1(std::string begin, std::string target, std::vector<std::string> words) {
    int answer = 0;

    const int size = words.size();

    std::unordered_map<std::string, std::unordered_set<std::string>> graph;
    for (int i = 0; i < size; ++i)
    {
        auto word1 = words[i];
        int count = 0;
        for (int j = 0; j < word1.size(); ++j)
        {
            if (word1[j] == begin[j])
            {
                count++;
            }
        }
        if (count + 1 == word1.size())
        {
            graph[begin].insert(word1);
        }

        for (int j = i + 1; j < size; ++j)
        {
            auto word2 = words[j];
            int count = 0;
            for (int k = 0; k < word1.size(); ++k)
            {
                if (word1[k] == word2[k])
                {
                    count++;
                }
            }

            if (count + 1 == word1.size())
            {
                graph[word1].insert(word2);
                graph[word2].insert(word1);
            }
        }
    }

    std::unordered_set<std::string> visit;

    std::function<void(std::string, int)> dfs = [&](std::string word, int count) {

        if (word == target)
        {
            if (0 == answer || answer > count)
            {
                answer = count;
            }
            return;
        }

        for (const auto& ele : graph[word])
        {
            if (visit.end() != visit.find(ele))
            {
                continue;
            }

            visit.insert(ele);

            dfs(ele, count + 1);

            visit.erase(ele);
        }
        };

    dfs(begin, 0);

    return answer;
}

void WordConversionTest()
{
    //std::string begin = "hit", target = "cog";
    //std::vector<std::string> words = { "hot", "dot", "dog", "lot", "log", "cog" }; // 4

    std::string begin = "hit", target = "cog";
    std::vector<std::string> words = { "hot", "dot", "dog", "lot", "log" }; // 0

    std::cout << "====================== Word Conversion Test Start ======================" << std::endl;

    std::cout << "Begin : " << begin << ", Target : " << target << std::endl;
    std::cout << "Words : [ ";
    for (const auto& ele : words)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(begin, target, words);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Word Conversion Test End ======================" << std::endl;
}
