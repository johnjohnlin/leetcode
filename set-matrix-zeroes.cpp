#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		const int h = matrix.size();
		if (h == 0) {
			return;
		}
		const int w = matrix[0].size();
		if (w == 0) {
			return;
		}
		int v0 = 1; // non-zero
		// project the zeros
		for (int y = 0; y < h; ++y) {
			if (matrix[y][0] == 0) {
				v0 = 0;
			}
			for (int x = 1; x < w; ++x) {
				if (matrix[y][x] == 0) {
					matrix[y][0] = 0;
					matrix[0][x] = 0;
				}
			}
		}
		// horizontal fill except idx 0
		for (int y = 1; y < h; ++y) {
			if (matrix[y][0] == 0) {
				for (int x = 1; x < w; ++x) {
					matrix[y][x] = 0;
				}
			}
		}
		// vertical fill except idx 0
		for (int x = 1; x < w; ++x) {
			if (matrix[0][x] == 0) {
				for (int y = 1; y < h; ++y) {
					matrix[y][x] = 0;
				}
			}
		}
		// horizontal flll idx 0
		if (matrix[0][0] == 0) {
			for (int x = 1; x < w; ++x) {
				matrix[0][x] = 0;
			}
		}
		// vertical fill idx 0
		if (v0 == 0) {
			for (int y = 0; y < h; ++y) {
				matrix[y][0] = 0;
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<int>> v1{{1},{0}};
	vector<vector<int>> v2{{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
	s.setZeroes(v1);
	s.setZeroes(v2);
	for (auto &vv: v1) {
		for (auto n: vv) {
			printf("%d ", n);
		}
		putchar('\n');
	}
	puts("===");
	for (auto &vv: v2) {
		for (auto n: vv) {
			printf("%d ", n);
		}
		putchar('\n');
	}
	puts("===");
	return 0;
}
