#include <algorithm>
#include <vector>
#include <limits>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		const int n = nums.size();
		assert(n != 0);
		int max_sum = numeric_limits<int>::min();
		int max_when_tail = 0;
		for (int num: nums) {
			max_when_tail = max(num, max_when_tail+num);
			max_sum = max(max_sum, max_when_tail);
		}
		return max_sum;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{2,3,-2,4};
	printf("%d\n", s.maxSubArray(v1));
	return 0;
}
