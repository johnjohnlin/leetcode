#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
class Solution {
	string RangeToString(const int a, const int b) {
		if (a == b) {
			return to_string(a);
		} else {
			return to_string(a) + "->" + to_string(b);
		}
	}
public:
	vector<string> summaryRanges(const vector<int>& nums) {
		vector<string> ret;
		if (nums.size() == 0) {
			return ret;
		}
		int range_begin = nums[0], range_end = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			const int num = nums[i];
			if (num == range_end+1) {
				++range_end;
			} else {
				ret.push_back(RangeToString(range_begin, range_end));
				range_begin = range_end = num;
			}
		}
		ret.push_back(RangeToString(range_begin, range_end));
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto ans = s.summaryRanges({0,1,2,4,5,7});
	for (auto &s: ans) {
		printf("%s\n", s.c_str());
	}
	return 0;
}
