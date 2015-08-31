#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		const int n = nums.size();
		return n*(n+1)/2 - accumulate(nums.begin(), nums.end(), 0);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	return 0;
}
