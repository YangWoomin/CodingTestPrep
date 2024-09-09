
#include	"hash_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_set>
#include	<string>

static std::vector<int> solution1(int n, std::vector<std::string> words) {
    std::vector<int> answer = { 0, 0 };

    std::unordered_set<std::string> wordsSet(words.size());
    char pre = '\0';
    for (int i = 0; i < words.size(); ++i)
    {
        if (1 >= words[i].size())
        {
            return { i % n + 1, i / n + 1 };
        }
        if ('\0' != pre && pre != words[i][0])
        {
            return { i % n + 1, i / n + 1 };
        }
        pre = words[i][words[i].size() - 1];
        if (false == wordsSet.insert(words[i]).second)
        {
            return { i % n + 1, i / n + 1 };
        }
    }

    return answer;
}

void WordChainGameTest()
{
	//std::vector<std::string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	//int n = 3; // [3,3]

    //std::vector<std::string> words = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
    //int n = 5; // [0,0]

    std::vector<std::string> words = { "hello", "one", "even", "never", "now", "world", "draw" };
    int n = 2; // [1,3]
	

	std::cout << "====================== Word Chain Game Test Start ======================" << std::endl;

	std::cout << "User Num : " << n << std::endl;
	std::cout << "Words : [ ";
	for (const auto& ele : words)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

	auto res = solution1(n, words);
	std::cout << "Result : [ " << res[0] << " " << res[1] << " ]" << std::endl;

	std::cout << "====================== Word Chain Game Test End ======================" << std::endl;
}
