#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>> grid) {
		const int h = grid.size();
		const int w = grid[0].size();
		if (grid[0][0] == 1) {
			return 0;
		}
		grid[0][0] = 1;
		for (int x = 1, can_reach = 1; x < w; ++x) {
			if (grid[0][x] == 1) {
				can_reach = 0;
			}
			grid[0][x] = can_reach;
		}
		for (int y = 1, can_reach = 1; y < h; ++y) {
			if (grid[y][0] == 1) {
				can_reach = 0;
			}
			grid[y][0] = can_reach;
		}
		for (int y = 1; y < h; ++y) {
			for (int x = 1; x < w; ++x) {
				if (grid[y][x] == 1) {
					grid[y][x] = 0;
				} else {
					grid[y][x] = grid[y-1][x] + grid[y][x-1];
				}
			}
		}
		return grid.back().back();
	}
};

int main(int argc, char const* argv[])
{
	// Yay
	return 0;
}
