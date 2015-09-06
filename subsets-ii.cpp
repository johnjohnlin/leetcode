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
	struct StackInfo {
		int num, count, max_count;
	};
	vector<StackInfo> buildBtStack(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<StackInfo> ret;
		ret.push_back({nums[0], 0, 1});
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == ret.back().num) {
				++ret.back().max_count;
			} else {
				ret.push_back({nums[i], 0, 1});
			}
		}
		return ret;
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> ret;
		const int n = nums.size();
		if (n == 0) {
			return ret;
		}
		vector<StackInfo> bt_stack = buildBtStack(nums);
		vector<int> subset;
		while (true) {
			ret.push_back(subset);
			bool bt_done = true;
			for (auto it = bt_stack.rbegin(); it != bt_stack.rend(); ++it) {
				if (it->count == it->max_count) {
					subset.resize(subset.size() - it->count);
					it->count = 0;
				} else {
					++(it->count);
					subset.push_back(it->num);
					bt_done = false;
					break;
				}
			}
			if (bt_done) {
				break;
			}
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> q1{1,2,2};
	PrintMatrix(s.subsetsWithDup(q1));
	return 0;
}
