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

class Solution {
public:
	int lengthOfLIS(const vector<int>& nums) {
#if 0
		// n*n
		vector<int> max_lens;
		int max_max_len = 0;
		for (size_t i = 0; i < nums.size(); ++i) {
			int max_len = 0;
			for (size_t j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					max_len = max(max_len, max_lens[j]);
				}
			}
			++max_len;
			max_max_len = max(max_max_len, max_len);
			max_lens.push_back(max_len);
		}
		return max_max_len;
#else
		// n*lg(n)
		vector<int> smallest_tails;
		for (int num: nums) {
			auto it = lower_bound(smallest_tails.begin(), smallest_tails.end(), num);
			if (it == smallest_tails.end()) {
				smallest_tails.push_back(num);
			} else {
				*it = num;
			}
		}
		return smallest_tails.size();
#endif
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.lengthOfLIS(vector<int>{})); // 0
	printf("%d\n", s.lengthOfLIS(vector<int>{100})); // 1
	printf("%d\n", s.lengthOfLIS(vector<int>{10,9,2,5,3,7,101,18})); // 4
	printf("%d\n", s.lengthOfLIS(vector<int>{10,9,2,5,3,4})); // 3
	return 0;
}
