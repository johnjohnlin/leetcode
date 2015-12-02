#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <cstdio>
using namespace std;

class Solution {
public:
	int longestConsecutive(const vector<int>& nums) {
		unordered_set<int> nums_set(nums.begin(), nums.end());
		int max_consecutive_count = 0;
		while (not nums_set.empty()) {
			int consecutive_count = 1, n;
			{
				// extract one
				auto it = nums_set.begin();
				n = *it;
				nums_set.erase(it);
			}
			// positive
			for (int i = n+1;; ++i) {
				auto it = nums_set.find(i);
				if (it == nums_set.end()) {
					break;
				} else {
					++consecutive_count;
					nums_set.erase(it);
				}
			}
			// negative
			for (int i = n-1;; --i) {
				auto it = nums_set.find(i);
				if (it == nums_set.end()) {
					break;
				} else {
					++consecutive_count;
					nums_set.erase(it);
				}
			}
			max_consecutive_count = max(consecutive_count, max_consecutive_count);
		}
		return max_consecutive_count;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	return 0;
}
