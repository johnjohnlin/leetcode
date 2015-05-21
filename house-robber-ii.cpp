#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
	typedef typename vector<int>::iterator It;
	int rob_original(It first, It last) {
		int max_when_norub_last = 0;
		int max_when_rub_last = 0;
		while (first != last) {
			int max_when_norub_last_tmp = max(max_when_rub_last, max_when_norub_last);
			int max_when_rub_last_tmp = max_when_norub_last + *first;
			max_when_norub_last = max_when_norub_last_tmp;
			max_when_rub_last = max_when_rub_last_tmp;
			++first;
		}
		return max(max_when_rub_last, max_when_norub_last);
	}
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		} else if (nums.size() == 1) {
			return nums[0];
		}
		return max(rob_original(nums.begin()+1, nums.end()), rob_original(nums.begin(), nums.end()-1));
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{1};
	vector<int> v2{1, 2};
	vector<int> v3{1, 2, 3, 100};
	printf("%d\n", s.rob(v1));
	printf("%d\n", s.rob(v2));
	printf("%d\n", s.rob(v3));
	return 0;
}
