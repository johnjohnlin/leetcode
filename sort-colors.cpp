#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums)
	{
		int histogram[3] = {};
		int cumsum[4] = {0};
		for (auto i: nums) {
			histogram[i] += 1;
		}
		partial_sum(histogram, histogram+sizeof(histogram)/sizeof(int), cumsum+1);
		for (int i = 0; i < 3; ++i) {
			fill(nums.begin()+cumsum[i], nums.begin()+cumsum[i+1], i);
		}
	}
};

int main(int argc, char const* argv[])
{
	vector<int> v{0,2,1,2,0,1,1,2,0,1,0,2,1,0,0,2,1};
	Solution s;
	s.sortColors(v);
	for (auto i: v) {
		printf("%d ", i);
	}
	putchar('\n');
	return 0;
}
