
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::string name) {
    int answer = 0;

    std::vector<int> alphaDiff(26, 27);
    for (int i = 0; i < 26; ++i)
    {
        alphaDiff[i] = std::min(i, 26 - i);
    }

    for (const auto& ele : name)
    {
        answer += alphaDiff[ele - 'A'];
    }

    const int size = name.size();
    std::function<int(int)> dfs = [&](int idx) {

        int offset = size * size;
        for (int right = 1; right < size; ++right)
        {
            int cur = (idx + right) % size;
            if ('A' != name[cur])
            {
                char tmp = name[cur];
                name[cur] = 'A';
                int ret = dfs(cur) + right;
                name[cur] = tmp;
                offset = std::min(offset, ret);
                break;
            }
        }
        for (int left = 1; left < size; ++left)
        {
            int cur = (idx - left + size) % size;
            if ('A' != name[cur])
            {
                char tmp = name[cur];
                name[cur] = 'A';
                int ret = dfs(cur) + left;
                name[cur] = tmp;
                offset = std::min(offset, ret);
                break;
            }
        }

        return size * size == offset ? 0 : offset;
        };

    name[0] = 'A';
    answer += dfs(0);

    return answer;
}

static int solution2(std::string name) {
    int answer = 0;

    const int size = name.size();

    std::vector<int> alphaOffset(26, 27);
    for (int i = 0; i < 26; ++i)
    {
        alphaOffset[i] = std::min(i, 26 - i);
    }

    for (int i = 0; i < size; ++i)
    {
        answer += alphaOffset[name[i] - 'A'];
    }

    int min = size;
    for (int i = 0; i < size; ++i)
    {
        int next = i + 1;
        while (size > next && 'A' == name[next])
        {
            next++;
        }

        min = std::min(min, i + size - next + std::min(i, size - next));
    }

    return answer + min;
}

void JoystickTest()
{
    std::string name = "JEROEN"; // 56
    //std::string name = "JAN"; // 23
    //std::string name = "JAZ"; // 11

    std::cout << "====================== Joystick Test Start ======================" << std::endl;

    std::cout << "Name : " << name << std::endl;
    
    auto res = solution2(name);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Joystick Test End ======================" << std::endl;
}
