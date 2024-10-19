
#include	"simulation_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<functional>

static int solution1(std::string name)
{
    int answer = 0;

    const int size = name.size();

    std::vector<int> alpha(26);
    for (int i = 0; i < alpha.size(); ++i)
    {
        alpha[i] = std::min(i, (int)alpha.size() - i);
    }

    for (const auto& ch : name)
    {
        answer += alpha[ch - 'A'];
    }

    int min = size - 1;
    std::function<void(int, int)> dfs = [&](int idx, int count) {

        int i = (idx + 1) % size, cnt1 = 1;
        while (i != idx && 'A' == name[i])
        {
            i = (i + 1) % size;
            cnt1++;
        }

        if (i != idx && min > count + cnt1)
        {
            char tmp = name[i];
            name[i] = 'A';
            dfs(i, count + cnt1);
            name[i] = tmp;
        }

        int j = (size + (idx - 1)) % size, cnt2 = 1;
        while (j != idx && 'A' == name[j])
        {
            j = (size + (j - 1)) % size;
            cnt2++;
        }

        if (j != idx && min > count + cnt2)
        {
            char tmp = name[j];
            name[j] = 'A';
            dfs(j, count + cnt2);
            name[j] = tmp;
        }

        if (idx == i && idx == j)
        {
            min = std::min(min, count);
        }
    };

    name[0] = 'A';
    dfs(0, 0);

    std::cout << min;

    return answer + min;
}

void JoystickTest()
{
    std::string name = "BBBBAAAABA"; // 12

	std::cout << "Name : " << name << std::endl;

	auto res = solution1(name);

	std::cout << "Result : " << res << std::endl;
}
