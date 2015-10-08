#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int findDuplicate(const vector<int>& nums) {
		const int THRESHOLD = 4, n = nums.size();
		int start = 1, range = n-1;

		while (range > THRESHOLD) {
			int count_l = 0;
			const int range_l = range/2;
			for (int num: nums) {
				const int idx = num-start;
				if (0 <= idx and idx < range) {
					if (idx < range_l) {
						++count_l;
					}
				}
			}
			printf("[%d,%d), l=%d\n", start, start+range, count_l);
			if (count_l > range_l) {
				range = range_l;
			} else {
				start += range_l;
				range -= range_l;
			}
		}

		bool appeared[THRESHOLD] = {};
		printf("Possible: [%d,%d)\n", start, start+range);
		for (int num: nums) {
			const int idx = num-start;
			if (0 <= idx and idx < range) {
				if (appeared[idx]) {
					return num;
				} else {
					appeared[idx] = true;
				}
			}
		}
		assert(0);
		return 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.findDuplicate({1,5,5,5,5,5,5,4,5,2,9})); // 5
	printf("%d\n", s.findDuplicate({2,5,9,6,9,3,8,9,7,1})); // 9
	return 0;
}
