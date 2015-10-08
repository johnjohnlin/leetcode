#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
}

inline void PrintMatrix(const vector<vector<int>> &m) {
	for (auto &v: m) {
		PrintVector(v);
	}
	puts("====");
}

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		const int h = board.size();
		if (h == 0) {
			return;
		}
		const int w = board[0].size();
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int neighbor = 0;
				for (int yy = max(y-1, 0); yy <= min(y+1, h-1); ++yy) {
					for (int xx = max(x-1, 0); xx <= min(x+1, w-1); ++xx) {
						neighbor += board[yy][xx]&1;
					}
				}
				// substract the center (no need for &1)
				neighbor -= board[y][x];
				printf("%d\n", neighbor);
				if (
					board[y][x] == 1 and neighbor >= 2 and neighbor <= 3 or
					board[y][x] == 0 and neighbor == 3
				) {
					board[y][x] |= 1 << 1;
				}
			}
		}

		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				board[y][x] >>= 1;
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<int>> b1{{1,1},{1,0}};
	s.gameOfLife(b1);
	PrintMatrix(b1);
	return 0;
}
