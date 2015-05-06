#include <vector>
#include <deque>
#include <cstdio>
#include <array>
using namespace std;

class Solution {
	void DFSClear(vector<vector<char>>& grid, const int y, const int x) {
		typedef array<int,2> ivec2;
		deque<ivec2> dfs_dq;
		dfs_dq.push_back({y, x});
		grid[y][x] = '0';
		while (dfs_dq.size() != 0) {
			const int cur_y = dfs_dq.front()[0];
			const int cur_x = dfs_dq.front()[1];
			dfs_dq.pop_front();
			static ivec2 neighbors[] = {
				{ 1,  0},
				{-1,  0},
				{ 0, -1},
				{ 0,  1}
			};
			for (auto& neighbor: neighbors) {
				const int ny = cur_y+neighbor[0];
				const int nx = cur_x+neighbor[1];
				if (
					0 <= nx && nx < w &&
					0 <= ny && ny < h &&
					grid[ny][nx] == '1'
				) {
					dfs_dq.push_back({ny,nx});
					grid[ny][nx] = '0';
				}
			}
		}
	}
	int w, h;
public:
	int numIslands(vector<vector<char>>& grid) {
		h = grid.size();
		w = (h == 0)? 0: grid[0].size();
		int island_count = 0;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (grid[y][x] == '1') {
					DFSClear(grid, y, x);
					island_count += 1;
				}
			}
		}
		return island_count;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<char>> v1{
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	vector<vector<char>> v2{
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};
	vector<vector<char>> v3{{'0'}};
	vector<vector<char>> v4{{'1'}};
	printf("%d\n", s.numIslands(v1));
	printf("%d\n", s.numIslands(v2));
	printf("%d\n", s.numIslands(v3));
	printf("%d\n", s.numIslands(v4));
	return 0;
}
