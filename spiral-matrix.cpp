#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		size_t h = matrix.size();
		if (h == 0) {
			return ret;
		}
		size_t w = matrix[0].size(), offset = 0;

		for (; w >= 2 and h >= 2; ++offset, w -= 2, h -= 2) {
			const size_t l = offset;
			const size_t u = offset;
			const size_t r = offset+w-1;
			const size_t b = offset+h-1;
			for (size_t j = l; j < r; ++j) {
				ret.push_back(matrix[u][j]);
			}
			for (size_t j = u; j < b; ++j) {
				ret.push_back(matrix[j][r]);
			}
			for (size_t j = r; j > l; --j) {
				ret.push_back(matrix[b][j]);
			}
			for (size_t j = b; j > u; --j) {
				ret.push_back(matrix[j][l]);
			}
		}
		if (h == 1) {
			const size_t l = offset;
			const size_t r = offset+w-1;
			for (size_t i = l; i <= r; ++i) {
				ret.push_back(matrix[offset][i]);
			}
		} else if (w == 1) {
			const size_t u = offset;
			const size_t b = offset+h-1;
			for (size_t i = u; i <= b; ++i) {
				ret.push_back(matrix[i][offset]);
			}
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<int>> v1{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
	vector<vector<int>> v2{{1,2,3},{4,5,6}};
	vector<vector<int>> v3{{1}};
	auto ans1 = s.spiralOrder(v1);
	auto ans2 = s.spiralOrder(v2);
	auto ans3 = s.spiralOrder(v3);
	for (auto n: ans1) {
		printf("%d ", n);
	}
	putchar('\n');
	for (auto n: ans2) {
		printf("%d ", n);
	}
	putchar('\n');
	for (auto n: ans3) {
		printf("%d ", n);
	}
	putchar('\n');
	return 0;
}
