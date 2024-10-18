
#include	"sort_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::string solution1(std::string s)
{
	std::vector<int> alphabets(26);

	for (const auto& ch : s)
	{
		alphabets[ch - 'a']++;
	}

	std::string res;

	for (int i = 0; i < alphabets.size(); ++i)
	{
		for (int j = 0; j < alphabets[i]; ++j)
		{
			res += 'a' + i;
		}
	}

	return res;
}

void CountingSortTest()
{
	//std::string s = "hello"; // "ehllo"
	std::string s = "algorithm"; // "aghilmort"

	std::cout << "String : " << s << std::endl;

	auto res = solution1(s);

	std::cout << "Result : " << res << std::endl;
}
