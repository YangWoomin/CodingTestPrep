
#include	"tests.h"

#include	<iostream>
#include	<algorithm>
#include	<string>

template <typename T>
bool NextPermutation(T&& arr)
{
	int i = arr.size() - 2;
	for (; i >= 0; --i)
	{
		if (arr[i] < arr[i + 1])
		{
			break;
		}
	}
	
	int j = arr.size() - 1;
	for (; j >= 0 && i >= 0; --j)
	{
		if (arr[i] < arr[j])
		{
			break;
		}
	}

	if (i < 0 || j < 0 || i == j)
	{
		return false;
	}

	std::swap(arr[i], arr[j]);

	for (i = i + 1, j = arr.size() - 1; i < j; ++i, --j)
	{
		std::swap(arr[i], arr[j]);
	}

	return true;
}

void PermutationTest()
{
	std::string arr = "12345";
	std::string arr2 = arr;

	std::cout << "====================== Permutation Test Start ======================" << std::endl;
	std::cout << "Permutations of... [" << arr << "]" << std::endl;
	std::cout << "Generating permutations..." << std::endl;

	std::size_t count = 0;
	while (true == NextPermutation(arr))
	{
		count++;

		std::cout << "[" << arr << "]" << std::endl;
		
		if (std::next_permutation(arr2.begin(), arr2.end()))
		{
			if (arr != arr2)
			{
				std::cout << "Invalid permutation!!" << std::endl;
				std::cout << "NextPermutation is : [" << arr << "], std::next_permutation is : [" << arr2 << "]" << std::endl;
				return;
			}
		}
	}

	std::cout << "The number of the permutations : " << count << std::endl;
	std::cout << "====================== Permutation Test End ======================" << std::endl;
	std::cout << std::endl;
}
