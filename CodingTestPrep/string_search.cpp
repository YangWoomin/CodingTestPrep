
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include	<string>
#include	<unordered_set>

static std::vector<bool> solution1(std::vector<std::string> string_list, std::vector<std::string> query_list)
{
	std::vector<bool> res;
	std::unordered_set<std::string> strs;

	for (const auto& ele : string_list)
	{
		strs.insert(ele);
	}

	for (const auto& ele : query_list)
	{
		res.push_back(strs.end() != strs.find(ele));
	}

	return res;
}

static std::vector<bool> solution2(std::vector<std::string> string_list, std::vector<std::string> query_list)
{
	std::vector<bool> res;
	std::unordered_set<long long> hash_table;

	const int p = 31;
	const long long m = 1000000007;
	
	for (const auto& ele : string_list)
	{
		long long hash_value = 0;
		for (int i = 0; i < ele.size(); ++i)
		{
			hash_value = (hash_value * p + ele[i]) % m;
		}
		hash_table.insert(hash_value);
	}

	for (const auto& ele : query_list)
	{
		long long hash_value = 0;
		for (int i = 0; i < ele.size(); ++i)
		{
			hash_value = (hash_value * p + ele[i]) % m;
		}
		res.push_back(hash_table.end() != hash_table.find(hash_value));
	}

	return res;
}

void StringSearchTest()
{
	std::vector<std::string> string_list = { "apple", "banana", "cherry" };
	std::vector<std::string> query_list = { "banana", "kiwi", "melon", "apple" }; // [true, false, false, true]

	std::cout << "====================== String Search Test Start ======================" << std::endl;

	std::cout << "String List : [ ";
	for (const auto& ele : string_list)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;
	std::cout << "Query List : [ ";
	for (const auto& ele : query_list)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

	auto res = solution2(string_list, query_list);
	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

	std::cout << "====================== String Search Test End ======================" << std::endl;
}
