#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		auto n = nums.size();
		if (n == 0) {
			return ret;
		}
		sort(nums.begin(), nums.end());
		vector<int> cur;
		vector<bool> flags(n);
		while (true) {
			ret.push_back(cur);
			bool done = true;
			for (size_t i = n; i-- > 0; ) {
				if (flags[i]) {
					flags[i] = false;
					cur.pop_back();
				} else {
					cur.push_back(nums[i]);
					flags[i] = true;
					done = false;
					break;
				}
			}
			if (done) {
				return ret;
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{1,2,3,4};
	auto ans = s.subsets(v);
	for (auto &v: ans) {
		for (auto r: v) {
			printf("%d ", r);
		}
		putchar('\n');
	}
	return 0;
}
