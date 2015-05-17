#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		auto search_this_row = upper_bound(matrix.begin(), matrix.end(), target,
			[](const int val, const vector<int> &v) {
				return val < v[0];
			}
		);
		if (search_this_row == matrix.begin()) {
			return false;
		}
		--search_this_row;
		return binary_search(search_this_row->begin(), search_this_row->end(), target);
	}
};
int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<int>> v{
		{1,3,5,7},
		{10,11,12,100},
		{101,200,400,10000},
	};
	printf("%d\n", s.searchMatrix(v, -1)); // 0
	printf("%d\n", s.searchMatrix(v, 1));  // 1
	printf("%d\n", s.searchMatrix(v, 10)); // 1
	printf("%d\n", s.searchMatrix(v, 2));  // 0
	printf("%d\n", s.searchMatrix(v, 100));// 1
	return 0;
}
