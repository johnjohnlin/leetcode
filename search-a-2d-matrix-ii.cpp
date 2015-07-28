#include <string>
#include <algorithm>
#include <utility>
#include <iterator>
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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		const int h = matrix.size();
		if (h == 0) {
			return false;
		}
		const int w = matrix[0].size();
		if (w == 0) {
			return false;
		}
		int left = 0;
		int upper = 0;
		int right = w-1;
		int lower = h-1;
		while (true) {
			// should use binary search
			while (left <= right and matrix[upper][right] >= target) {
				if (matrix[upper][right] == target) {
					return true;
				}
				--right;
			}
			while (left <= right and matrix[lower][left] <= target) {
				if (matrix[lower][left] == target) {
					return true;
				}
				++left;
			}
			if (left > right) {
				return false;
			}
			while (upper <= lower and matrix[lower][left] >= target) {
				if (matrix[lower][left] == target){
					return true;
				}
				--lower;
			}
			while (upper <= lower and matrix[upper][right] <= target) {
				if (matrix[upper][right] == target){
					return true;
				}
				++upper;
			}
			if (upper > lower) {
				return false;
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	vector<vector<int>> v1 {{0}};
	vector<vector<int>> v2 {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	Solution s;
	printf("%d\n", int(s.searchMatrix(v1, -1))); // 0
	printf("%d\n", int(s.searchMatrix(v1, 0))); // 1
	printf("%d\n", int(s.searchMatrix(v1, 1))); // 0
	printf("%d\n", int(s.searchMatrix(v2, 5))); // 1
	printf("%d\n", int(s.searchMatrix(v2, 20))); // 0
	return 0;
}
