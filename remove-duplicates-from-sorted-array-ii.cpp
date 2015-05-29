#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		const int n = nums.size();
		if (n <= 2) {
			return n;
		}

		int state_count = 1;
		int state_number = nums[0];
		int write_idx = 1;
		for (int i = 1; i < n; ++i) {
			const int num = nums[i];
			if (num == state_number) {
				if (state_count == 2) {
					continue;
				} else {
					++state_count;
				}
			} else {
				state_count = 1;
				state_number = num;
			}
			nums[write_idx] = num;
			++write_idx;
		}
		nums.resize(write_idx);
		return write_idx;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{1,1,1,2,2,3};
	const int n = s.removeDuplicates(v);
	printf("After remove: %d left\n", n);
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
	return 0;
}
