
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <tuple>
#include    <algorithm>

static std::string solution1(std::string m, std::vector<std::string> musicinfos) {
    std::string answer = "(None)";

    std::vector<std::tuple<int, int, std::string>> res;

    auto tokenizer = [](const std::string& m) {
        std::vector<std::string> res;
        for (int i = 0; i < m.size(); ++i)
        {
            if ('#' != m[i])
            {
                res.push_back(std::string(1, m[i]));
            }
            else
            {
                std::string t = res.back() + '#';
                res.pop_back();
                res.push_back(t);
            }
        }
        return res;
        };

    const std::vector<std::string> score = tokenizer(m);
    const int size = score.size();

    for (int k = 0; k < musicinfos.size(); ++k)
    {
        const auto info = musicinfos[k];

        int startHour = std::stoi(info.substr(0, 2));
        int startMin = std::stoi(info.substr(3, 2));
        int endHour = std::stoi(info.substr(6, 2));
        int endMin = std::stoi(info.substr(9, 2));
        std::size_t idx = info.rfind(',');
        std::string title = info.substr(12, idx - 12);
        std::vector<std::string> music = tokenizer(info.substr(idx + 1));

        if (endMin == startMin && endHour == startHour)
        {
            continue;
        }

        int durationHour = endHour - startHour;
        int durationMin = endMin - startMin;
        if (0 > durationMin)
        {
            durationHour--;
            durationMin += 60;
        }

        int duration = durationMin + durationHour * 60;

        bool repeatable = true;
        if (music.size() > duration)
        {
            repeatable = false;
            music = std::vector<std::string>(music.begin(), music.begin() + duration);
        }

        for (int i = 0; i < music.size(); ++i)
        {
            bool found = true;
            int idx = i, count = 0, j = 0;
            while (j < size && count < duration)
            {
                if (music[idx] != score[j])
                {
                    found = false;
                    break;
                }

                j++;
                idx++;
                count++;
                if (idx == music.size())
                {
                    if (!repeatable)
                    {
                        if (j < size)
                        {
                            found = false;
                        }
                        break;
                    }
                    idx = 0;
                }
            }

            if (found && size == j)
            {
                res.push_back({ k, duration, title });
            }
        }
    }

    std::sort(res.begin(), res.end(), [](auto& lhs, auto& rhs) {
        int idx1 = std::get<0>(lhs);
        int idx2 = std::get<0>(rhs);
        int duration1 = std::get<1>(lhs);
        int duration2 = std::get<1>(rhs);
        std::string title1 = std::get<2>(lhs);
        std::string title2 = std::get<2>(rhs);
        if (duration1 == duration2)
        {
            return idx1 < idx2;
        }
        return duration1 > duration2;
        });

    if (!res.empty())
    {
        answer = std::get<2>(res[0]);
    }

    return answer;
}

void TheSongJustNowTest()
{
    //std::string m = "ABCDEFG";
    //std::vector<std::string> musicinfos = {
    //    "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"
    //}; // "HELLO"

    //std::string m = "CC#BCC#BCC#BCC#B";
    //std::vector<std::string> musicinfos = {
    //    "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"
    //}; // "FOO"

    std::string m = "ABC";
    std::vector<std::string> musicinfos = {
        "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"
    }; // "WORLD"

    std::cout << "====================== The Song Just Now Test Start ======================" << std::endl;

    std::cout << "Music : " << m << std::endl;
    std::cout << "Music Info : [ ";
    for (const auto& ele : musicinfos)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(m, musicinfos);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== The Song Just Now Test End ======================" << std::endl;
}
