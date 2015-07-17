#include <algorithm>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		const int n = nums.size();
		assert(n != 0);
		if (n == 1) {
			return nums[0];
		}
		int max_product = 0;
		int max_when_tail = 0;
		int min_when_tail = 0;
		for (int num: nums) {
			int max_when_tail_next;
			int min_when_tail_next;
			if (num > 0) {
				max_when_tail_next = max_when_tail * num;
				min_when_tail_next = min_when_tail * num;
			} else if (num < 0) {
				max_when_tail_next = min_when_tail * num;
				min_when_tail_next = max_when_tail * num;
			} else {
				max_when_tail_next = 0;
				min_when_tail_next = 0;
			}
			max_when_tail = max(num, max_when_tail_next);
			min_when_tail = min(num, min_when_tail_next);
			max_product = max(max_product, max_when_tail);
		}
		return max_product;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{2,3,-2,4};
	printf("%d\n", s.maxProduct(v1));
	return 0;
}
