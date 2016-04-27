#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool increasingTriplet(const vector<int> &nums) {
		if (nums.size() < 3) {
			return false;
		}
		bool has_2 = false;
		int min_tail_1 = nums[0], min_tail_2;
		for (int n: nums) {
			if (has_2 and n > min_tail_2) {
				return true;
			}
			if (n > min_tail_1) {
				if (has_2) {
					min_tail_2 = min(n, min_tail_2);
				} else {
					min_tail_2 = n;
					has_2 = true;
				}
			}
			min_tail_1 = min(min_tail_1, n);
		}
		return false;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", int(s.increasingTriplet({1,2,3,4,5})));
	printf("%d\n", int(s.increasingTriplet({5,4,3,2,1})));
	printf("%d\n", int(s.increasingTriplet({100,200,200})));
	printf("%d\n", int(s.increasingTriplet({2147483646,2147483647,2147483647})));
	return 0;
}
