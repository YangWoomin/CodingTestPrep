
#include	"hash_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_map>
#include	<string>

static bool solution1(std::vector<std::string> phone_book) {
    std::unordered_map<std::string, int> nums;
    for (auto it = phone_book.begin(); phone_book.end() != it; ++it)
    {
        for (int j = 0; j < it->size() - 1; ++j)
        {
            auto res = nums.insert(std::make_pair(it->substr(0, j + 1), 0)); // 0 : prefix
            if (false == res.second && res.first->second != 0)
            {
                return false;
            }
        }

        if (false == nums.insert(std::make_pair(*it, 1)).second) // 1 : full text
        {
            return false;
        }
    }

    return true;
}

void PhoneBookTest()
{
    //std::vector<std::string> phoneBook = { "119", "97674223", "1195524421" }; // false
    //std::vector<std::string> phoneBook = { "123","456","789" }; // true
    std::vector<std::string> phoneBook = { "12","123","1235","567","88" }; // false

	std::cout << "====================== Phone Book Test Start ======================" << std::endl;

	std::cout << "Phone Book : [ ";
	for (const auto& ele : phoneBook)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

	auto res = solution1(phoneBook);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Phone Book Test End ======================" << std::endl;
}
