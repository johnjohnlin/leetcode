#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
class Solution {
public:
	vector<int> searchRange(const vector<int>& nums, int target) {
		auto l = lower_bound(nums.begin(), nums.end(), target);
		if (l != nums.end() and *l == target) {
			auto r = upper_bound(l, nums.end(), target);
			const int li = l-nums.begin();
			const int ri = r-nums.begin()-1;
			return vector<int>{li, ri};
		}
		return vector<int>{-1,-1};
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{5, 7, 7, 8, 8, 10};
	for (int i = 4; i <= 11; ++i) {
		auto ans = s.searchRange(v, i);
		printf("%2d %3d~ %3d\n", i, ans[0], ans[1]);
	}
	return 0;
}
