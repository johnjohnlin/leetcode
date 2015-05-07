#include <cstdio>
#include <vector>
#include <array>
#include <deque>
using namespace std;

enum PixelType:char {
	O = 'O',
	X = 'X',
	NOT_ISOLATE = '!'
};


class Solution {
	void DFSClear(vector<vector<char>>& grid, const int y, const int x, PixelType from, PixelType to) {
		typedef array<int,2> ivec2;
		deque<ivec2> dfs_dq;
		dfs_dq.push_back({y, x});
		grid[y][x] = to;
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
					grid[ny][nx] == from
				) {
					dfs_dq.push_back({ny,nx});
					grid[ny][nx] = to;
				}
			}
		}
	}
	int w, h;
public:
	void solve(vector<vector<char>> &grid) {
		h = grid.size();
		w = (h == 0)? 0: grid[0].size();
		if (w == 0 || h == 0) {
			return;
		}
		// step 1: preserve the boundary
		for (int x = 0; x < w; ++x) {
			if (grid[0][x] == PixelType::O) {
				DFSClear(grid, 0, x, PixelType::O, PixelType::NOT_ISOLATE);
			}
			if (grid[h-1][x] == PixelType::O) {
				DFSClear(grid, h-1, x, PixelType::O, PixelType::NOT_ISOLATE);
			}
		}
		for (int y = 1; y < h-1; ++y) {
			if (grid[y][0] == PixelType::O) {
				DFSClear(grid, y, 0, PixelType::O, PixelType::NOT_ISOLATE);
			}
			if (grid[y][w-1] == PixelType::O) {
				DFSClear(grid, y, w-1, PixelType::O, PixelType::NOT_ISOLATE);
			}
		}
		// step 2: convert the required format
		for (auto &row : grid) {
			for (auto &p: row) {
				if (p == PixelType::NOT_ISOLATE) {
					p = PixelType::O;
				} else {
					p = PixelType::X;
				}
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<char>> v1{
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'}
	};
	s.solve(v1);
	for (auto &row : v1) {
		for (auto p: row) {
			printf("%c ", p);
		}
		putchar('\n');
	}
	return 0;
}
