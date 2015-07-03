#include <string>
#include <algorithm>
#include <utility>
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
	void nextPermutation(vector<int>& nums) {
		int i = nums.size()-2;
		while (i >= 0 and nums[i] >= nums[i+1]) {
			--i;
		}
		if (i == -1) {
			reverse(begin(nums), end(nums));
		} else {
			for (int j = nums.size()-1; j > i; --j) {
				if (nums[j] > nums[i]) {
					swap(nums[i], nums[j]);
					reverse(nums.begin()+i+1, nums.end());
					break;
				}
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{1,2,3}; // 1,3,2
	vector<int> v2{3,2,1}; // 1,2,3
	vector<int> v3{1,1,5}; // 1,5,1
	s.nextPermutation(v1);
	s.nextPermutation(v2);
	s.nextPermutation(v3);
	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	return 0;
}
