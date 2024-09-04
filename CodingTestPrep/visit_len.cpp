
#include	"array_test.h"

#include	<iostream>
#include	<vector>
#include	<string>

static int solution1(std::string dirs)
{
	std::vector<std::vector<std::vector<int>>> map(10, std::vector<std::vector<int>>(10, std::vector<int>(4, 0)));
	int x = map[0].size() / 2;
	int y = map.size() / 2;
	int len = 0;

	for (int i = 0; i < dirs.size(); ++i)
	{
		int dir = 0;
		int nx = x;
		int ny = y;
		switch (dirs[i])
		{
		case 'U':
		{
			ny += 1;
			break;
		}
		case 'L':
		{
			nx -= 1;
			dir = 1;
			break;
		}
		case 'D':
		{
			ny -= 1;
			dir = 2;
			break;
		}
		case 'R':
		{
			nx += 1;
			dir = 3;
			break;
		}
		}

		if (nx >= map[0].size())
		{
			continue;
		}
		if (nx < 0)
		{
			continue;
		}
		if (ny >= map.size())
		{
			continue;
		}
		if (ny < 0)
		{
			continue;
		}

		if (0 == map[y][x][dir])
		{
			len++;
		}

		map[y][x][dir] = 1;
		map[ny][nx][(dir + 2) % 4] = 1;

		x = nx;
		y = ny;
	}

	return len;
}

void VisitLenTest()
{
	//std::string dirs = "ULURRDLLU";
	std::string dirs = "LULLLLLU";

	std::cout << "====================== Visit Len Test Start ======================" << std::endl;

	std::cout << "Dirs : " << dirs << std::endl;

	int res = solution1(dirs);

	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Visit LenTest Start ======================" << std::endl;
}
