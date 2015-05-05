#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int max_when_norub_last = 0;
		int max_when_rub_last = 0;
		for (auto num: nums) {
			int max_when_norub_last_tmp = max(max_when_rub_last, max_when_norub_last);
			int max_when_rub_last_tmp = max_when_norub_last + num;
			max_when_norub_last = max_when_norub_last_tmp;
			max_when_rub_last = max_when_rub_last_tmp;
		}
		return max(max_when_rub_last, max_when_norub_last);
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
