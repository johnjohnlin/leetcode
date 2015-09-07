#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdio>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, const int target) {
		const int n = nums.size();
		sort(nums.begin(), nums.end());
		int ans, min_abs = numeric_limits<int>::max();
		for (int i = 0; i < n-2; ++i) {
			int l = i+1, r = n-1;
			while (l < r) {
				const int sum = nums[i] + nums[l] + nums[r];
				if (sum < target) {
					++l;
					const int cur_abs = target - sum;
					if (cur_abs < min_abs) {
						ans = sum;
						min_abs = cur_abs;
					}
				} else if (sum > target) {
					--r;
					const int cur_abs = sum - target;
					if (cur_abs < min_abs) {
						ans = sum;
						min_abs = cur_abs;
					}
				} else {
					return target;
				}
			}
		}
		return ans;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> q1{-1,2,1,4};
	vector<int> q2{1,1,1,0};
	printf("%d\n", s.threeSumClosest(q1, 2));
	printf("%d\n", s.threeSumClosest(q2, -100));
	return 0;
}
