
#include	"test3.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <functional>
#include    <unordered_set>

static int solution1(std::vector<std::string> user_id, std::vector<std::string> banned_id) {

    int size = banned_id.size();
    std::vector<std::vector<std::string>> banList;
    for (int i = 0; i < size; ++i)
    {
        auto& bid = banned_id[i];

        std::vector<std::string> targets;

        for (const auto& uid : user_id)
        {
            if (uid.size() != bid.size())
            {
                continue;
            }

            bool match = true;
            for (int j = 0; j < bid.size(); ++j)
            {
                if ('*' != bid[j] && bid[j] != uid[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                targets.push_back(uid);
            }
        }

        if (!targets.empty())
        {
            banList.push_back(targets);
        }
    }

    size = banList.size();

    std::vector<std::unordered_set<std::string>> all;
    auto insert = [&](std::unordered_set<std::string>& set) {
        for (const auto& ele : all)
        {
            if (ele == set)
            {
                return;
            }
        }
        all.push_back(set);
        };

    std::unordered_set<std::string> set;
    std::function<void(int)> dfs = [&](int idx) {

        if (size <= idx)
        {
            insert(set);
            return;
        }

        for (auto& target : banList[idx])
        {
            if (set.end() != set.find(target))
            {
                continue;
            }

            set.insert(target);

            dfs(idx + 1);

            set.erase(target);
        }
        };

    dfs(0);

    return all.size();
}

void MaliciousUserTest()
{
    //std::vector<std::string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    //std::vector<std::string> banned_id = { "fr*d*", "abc1**" }; // 2

    //std::vector<std::string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    //std::vector<std::string> banned_id = { "*rodo", "*rodo", "******" }; // 2

    std::vector<std::string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    std::vector<std::string> banned_id = { "fr*d*", "*rodo", "******", "******" }; // 3

    std::cout << "====================== Malicious User Test Start ======================" << std::endl;

    std::cout << "User Id : [ ";
    for (const auto& ele : user_id)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Banned Id : [ ";
    for (const auto& ele : banned_id)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(user_id, banned_id);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Malicious User Test End ======================" << std::endl;
}
