#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int minPatches(const vector<int>& nums, int n) {
		int patched = 0;
		unsigned can_reach = 0;
		auto cur = nums.begin();
		while (can_reach < n) {
			if (cur == nums.end() or *cur > can_reach + 1) {
				can_reach = can_reach*2 + 1;
				++patched;
			} else {
				can_reach += *cur;
				++cur;
			}
		}
		return patched;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.minPatches({1,3}, 6));
	printf("%d\n", s.minPatches({1,5,10}, 20));
	printf("%d\n", s.minPatches({1,2,2}, 5));
	return 0;
}
