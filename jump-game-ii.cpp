#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		const int goal = nums.size() - 1;
		int n_steps = 0;
		int min_at_this_step = 0;
		int max_at_this_step = 0;
		while (true) {
			if (max_at_this_step >= goal) {
				return n_steps;
			}
			const int min_at_next_step = max_at_this_step + 1;
			int max_at_next_step = -1;
			for (int i = min_at_this_step; i <= max_at_this_step; ++i) {
				max_at_next_step = max(max_at_next_step, i+nums[i]);
			}
			min_at_this_step = min_at_next_step;
			max_at_this_step = max_at_next_step;
			++n_steps;
		}
		assert(0);
		return 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{2,3,1,1,4};
	vector<int> v2{0};
	printf("%d\n", s.jump(v1));
	printf("%d\n", s.jump(v2));
	return 0;
}
