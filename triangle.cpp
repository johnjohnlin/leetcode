#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		if (triangle.size() == 0) {
			return 0;
		}
		for (size_t layer = 1; layer < triangle.size(); ++layer) {
			vector<int> &prev = triangle[layer-1];
			vector<int> &cur = triangle[layer];
			cur[    0] += prev[      0];
			cur[layer] += prev[layer-1];
			for (size_t i = 1; i < layer; ++i) {
				cur[i] += min(prev[i], prev[i-1]);
			}
		}
		vector<int> &b = triangle.back();
		return *min_element(b.begin(), b.end());
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<int>> v{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
	printf("%d\n", s.minimumTotal(v));
	for (auto &a: v) {
		for (auto b: a) {
			printf("%d ", b);
		}
		putchar('\n');
	}
	return 0;
}
