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
	void moveZeroes(vector<int>& nums) {
		auto it = remove_if(nums.begin(), nums.end(), bind(equal_to<int>(), placeholders::_1, 0));
		fill(it, nums.end(), 0);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{3,0,2,5,1,90,9,2,0,0,3,0};
	s.moveZeroes(v1);
	PrintVector(v1);
	return 0;
}
