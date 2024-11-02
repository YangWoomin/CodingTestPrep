
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

struct Trie
{
    std::unordered_map<char, Trie*> next;
    std::unordered_map<char, int> count;

    ~Trie()
    {
        for (const auto& [ch, trie] : next)
        {
            delete trie;
        }
    }

    void insert(const std::string& str, int idx)
    {
        if (str.size() > idx)
        {
            if (nullptr == next[str[idx]])
            {
                next[str[idx]] = new Trie();
            }
            next[str[idx]]->insert(str, idx + 1);
            count[str[idx]]++;
        }
    }

    int inspect(const std::string& str, int idx)
    {
        if (str.size() == idx + 1)
        {
            return idx + 1;
        }

        if (1 == count[str[idx]])
        {
            return idx + 1;
        }

        if (next[str[idx]])
        {
            return next[str[idx]]->inspect(str, idx + 1);
        }

        return -1;
    }
};

static int solution1(std::vector<std::string> words) {
    int answer = 0;

    Trie* root = new Trie();

    for (const auto& word : words)
    {
        root->insert(word, 0);
    }

    for (const auto& word : words)
    {
        int res = root->inspect(word, 0);
        if (0 < res)
        {
            answer += res;
        }
    }

    delete root;

    return answer;
}

void AutoCompleteTest()
{
    //std::vector<std::string> words = { "go","gone","guild" }; // 7
    //std::vector<std::string> words = { "abc","def","ghi","jklm" }; // 4
    std::vector<std::string> words = { "word","war","warrior","world" }; // 15

    std::cout << "====================== Auto Complete Test Start ======================" << std::endl;

    std::cout << "Words : [ ";
    for (const auto& ele : words)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(words);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Auto Complete Test End ======================" << std::endl;
}
