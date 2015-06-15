#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <memory>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		const int h = matrix.size();
		if (h == 0) {
			return 0;
		}
		const int w = matrix[0].size();
		if (w == 0) {
			return 0;
		}
		int max_border = 0;
		unique_ptr<int[]> dp_table(new int[w*h]);
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int border;
				if (matrix[y][x] == '1') {
					int top_border = (y == 0? 0: dp_table[(y-1)*w+x]);
					int left_border = (x == 0? 0: dp_table[y*w+(x-1)]);
					if (top_border == left_border) {
						if (matrix[y-top_border][x-left_border] == '1') {
							border = top_border+1;
						} else {
							border = top_border;
						}
					} else {
						border = min(top_border, left_border) + 1;
					}
				} else {
					border = 0;
				}
				dp_table[y*w+x] = border;
				max_border = max(max_border, border);
			}
		}
		return max_border * max_border;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<char>> v{
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'},
	};
	printf("%d\n", s.maximalSquare(v));
	return 0;
}
