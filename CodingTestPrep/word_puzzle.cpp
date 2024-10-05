
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>
#include    <queue>

#include    <unordered_set>
#include    <unordered_map>

// brute force (time over)
static int solution1(std::vector<std::string> strs, std::string t)
{
    int answer = 0;

    std::unordered_set<std::string> set;
    for (const auto& ele : strs)
    {
        set.insert(ele);
    }

    std::unordered_map<std::string, int> dp;

    std::string sub;
    for (int i = 0; i < t.size(); ++i)
    {
        sub += t[i];

        int min = t.size() + 1;
        for (const auto& [key, val] : dp)
        {
            auto rest = t.substr(key.size(), i - key.size() + 1);
            if (set.end() == set.find(rest))
            {
                continue;
            }

            if (val + 1 < min)
            {
                min = val + 1;
            }
        }
        if (t.size() + 1 > min)
        {
            dp[sub] = min;
        }
        if (set.end() != set.find(sub))
        {
            dp[sub] = 1;
        }
    }

    answer = dp[t];
    return answer > 0 ? answer : -1;
}

// bfs + priority queue (time over)
static int solution2(std::vector<std::string> strs, std::string t)
{
    int answer = -1;

    const int size = t.size();

    std::vector<int> visit(size + 1, size + 1);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty())
    {
        auto [idx, count] = pq.top();
        pq.pop();

        if (size <= idx)
        {
            if (-1 == answer || answer > count)
            {
                answer = count;
            }
            continue;
        }

        if (visit[idx] <= count)
        {
            continue;
        }
        visit[idx] = count;

        for (const auto& str : strs)
        {
            bool same = true;
            for (int i = 0; i < str.size(); ++i)
            {
                if (size <= idx + i)
                {
                    same = false;
                    break;
                }
                if (t[idx + i] != str[i])
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                if (visit[idx + str.size()] > count + 1)
                {
                    pq.push({ idx + str.size(), count + 1 });
                }
            }
        }
    }

    return answer;
}

// dp
static int solution3(std::vector<std::string> strs, std::string t)
{

    std::vector<int> dp(t.size() + 1, t.size() + 1);
    dp[0] = 0;

    for (int i = 1; i <= t.size(); ++i)
    {
        for (const auto& str : strs)
        {
            const int len = str.size();
            if (i < len)
            {
                continue;
            }

            bool same = true;
            for (int j = 0; j < len; ++j)
            {
                if (t[i - 1 - j] != str[len - 1 - j])
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                if (dp[i - len] + 1 < dp[i])
                {
                    dp[i] = dp[i - len] + 1;
                }
            }
        }
    }

    return dp[t.size()] < t.size() + 1 ? dp[t.size()] : -1;
}

void WordPuzzleTest()
{
    //std::vector<std::string> strs = { "ba","na","n","a" };
    //std::string t = "banana"; // 3

    std::vector<std::string> strs = { "app","ap","p","l","e","ple","pp" };
    std::string t = "apple"; // 2

    //std::vector<std::string> strs = { "ba","an","nan","ban","n" };
    //std::string t = "banana"; // -1

    std::cout << "====================== Word Puzzle Test Start ======================" << std::endl;

    std::cout << "Strs : [ ";
    for (const auto& ele : strs)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "T : " << t << std::endl;

    auto res = solution2(strs, t);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Word Puzzle Test End ======================" << std::endl;
}
