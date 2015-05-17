#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int cur_farthest = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (cur_farthest < i) {
				return false;
			}
			cur_farthest = max(cur_farthest, i+nums[i]);
		}
		return true;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{2,3,1,1,4};
	vector<int> v2{3,2,1,0,4};
	printf("%d\n", (int)s.canJump(v1)); // 1
	printf("%d\n", (int)s.canJump(v2)); // 0
	return 0;
}
