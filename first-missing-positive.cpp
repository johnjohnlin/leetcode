#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		const int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (0 < nums[i] and nums[i] <= n and nums[i] != nums[nums[i]-1]) {
				swap(nums[i], nums[nums[i]-1]);
			}
		}
		int i = 1;
		for (const int num: nums) {
			if (num != i) {
				break;
			} else {
				++i;
			}
		}
		return i;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> q1{3, 4, -1, 1};
	vector<int> q2{1, 1};
	printf("%d\n", s.firstMissingPositive(q1));
	printf("%d\n", s.firstMissingPositive(q2));
	return 0;
}
