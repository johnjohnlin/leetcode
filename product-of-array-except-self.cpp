#include <algorithm>
#include <functional>
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
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ret(nums.size());
		ret.front() = 1;
		partial_sum(nums.begin(), nums.end()-1, ret.begin()+1, multiplies<int>());
		partial_sum(nums.rbegin(), nums.rend()-1, nums.rbegin(), multiplies<int>());
		transform(nums.begin()+1, nums.end(), ret.begin(), ret.begin(), multiplies<int>());
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{1,2,3,4};
	auto ans1 = s.productExceptSelf(v1);
	PrintVector(ans1);
	return 0;
}
