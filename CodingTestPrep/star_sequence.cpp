
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

static int solution1(std::vector<int> a) {
    int answer = 0;

    std::unordered_map<int, int> count1;
    for (const auto& ele : a)
    {
        count1[ele]++;
    }

    std::vector<std::pair<int, int>> count2;
    for (const auto& [num, cnt] : count1)
    {
        count2.push_back({ cnt, num });
    }

    std::sort(count2.begin(), count2.end(), [](auto& lhs, auto& rhs) {
        return lhs.first > rhs.first;
        });

    for (const auto& [cnt, num] : count2)
    {
        if (answer >= cnt)
        {
            break;
        }

        int i = 0, last = -1, pair = 0;
        while (a.size() > i)
        {
            if (num == a[i])
            {
                int j = i - 1;
                while (last < j && num == a[j])
                {
                    j--;
                }
                if (last < j && num != a[j])
                {
                    pair++;
                    last = i;
                    i++;
                    continue;
                }

                j = i + 1;
                while (j < a.size() && num == a[j])
                {
                    j++;
                }
                if (j < a.size() && num != a[j])
                {
                    pair++;
                    last = j;
                    i = j + 1;
                    continue;
                }
            }

            i++;
        }

        answer = std::max(answer, pair);
    }

    return answer * 2;
}

void StarSequenceTest()
{
    std::vector<int> a = { 5,2,3,3,5,3 }; // 4

    std::cout << "====================== Start Sequence Test Start ======================" << std::endl;

    std::cout << "Array : [ ";
    for (const auto& ele : a)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(a);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Start Sequence Test End ======================" << std::endl;
}
