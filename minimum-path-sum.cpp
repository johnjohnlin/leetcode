#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const size_t h = grid.size();
		const size_t w = grid[0].size();
		for (size_t x = 1; x < w; ++x) {
			grid[0][x] += grid[0][x-1];
		}
		for (size_t y = 1; y < h; ++y) {
			grid[y][0] += grid[y-1][0];
			for (size_t x = 1; x < w; ++x) {
				grid[y][x] += min(grid[y-1][x], grid[y][x-1]);
			}
		}
		return grid.back().back();
	}
};

int main(int argc, char const* argv[])
{
	vector<vector<int>> v{{1, 2, 3, 4}, {100, 20, 1, 1}};
	Solution s;
	printf("%d\n", s.minPathSum(v));
	return 0;
}
