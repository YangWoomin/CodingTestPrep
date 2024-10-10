
#include	"hash_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<unordered_set>
#include	<cmath>

static std::vector<bool> solution1(std::vector<std::string> string_list, std::vector<std::string> query_list)
{
	std::vector<bool> res;

	auto hfunc = [](const std::string& str) {
		long long value = 0;
		const int p = 31;

		for (int i = 0; i < str.size(); ++i)
		{
			//value += (long long)(str[i] * std::pow(p, i)) % 1000000007;
			value = (value * p + str[i]) % 1000000007;
		}

		return value;
	};

	std::unordered_set<long long> hash;
	for (const auto& ele : string_list)
	{
		long long hv = hfunc(ele);
		hash.insert(hv);
	}

	for (const auto& ele : query_list)
	{
		long long hv = hfunc(ele);
		if (hash.end() != hash.find(hv))
		{
			res.push_back(true);
		}
		else
		{
			res.push_back(false);
		}
	}

	return res;
}

void StringSearchTest()
{
	std::vector<std::string> string_list = { "apple", "banana", "cherry" };
	std::vector<std::string> query_list = { "banana", "kiwi", "melon", "apple"}; // [true, false, false, true]

	std::cout << "String List : [ ";
	for (const auto& ele : string_list)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Query List : [ ";
	for (const auto& ele : query_list)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(string_list, query_list);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
