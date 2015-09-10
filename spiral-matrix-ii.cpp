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
	vector<vector<int>> generateMatrix(const int n) {
		vector<vector<int>> mat(n);
		for (auto&& r: mat) {
			r.resize(n);
		}
		int num = 1;
		for (int i = 0; i < n/2; ++i) {
			const int edge = n-i*2-1;
			for (int j = 0; j < edge; ++j) {
				mat[i][i+j] = num++;
			}
			for (int j = 0; j < edge; ++j) {
				mat[i+j][n-1-i] = num++;
			}
			for (int j = 0; j < edge; ++j) {
				mat[n-1-i][n-1-i-j] = num++;
			}
			for (int j = 0; j < edge; ++j) {
				mat[n-1-i-j][i] = num++;
			}
		}
		if (n % 2 == 1) {
			mat[n/2][n/2] = num;
		}
		return mat;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	PrintMatrix(s.generateMatrix(7));
	return 0;
}
