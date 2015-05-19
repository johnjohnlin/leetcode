#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		const auto n = nums.size();
		if (n == 0) {
			return ret;
		} else if (n == 1) {
			ret.push_back(nums);
			return ret;
		}
		sort(nums.begin(), nums.end());
		while (true) {
			ret.push_back(nums);
			size_t i = n-2;
			while (true) {
				if (nums[i] < nums[i+1]) {
					break;
				} else if (i == 0) {
					return ret;
				} else {
					--i;
				}
			}
			for (size_t j = n; j-- >= i;) {
				if (nums[j] > nums[i]) {
					swap(nums[i], nums[j]);
					reverse(nums.begin()+i+1, nums.end());
					break;
				}
			}
		}
		assert(0);
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{6,3,2,7,4,-1}; // 6! = 720
	// vector<int> v{1,1,2,3,3,3,3,4}; // 8!/2!/4! = 840
	auto ans = s.permute(v);
	for (auto& v: ans) {
		for (auto i: v) {
			printf("%d ", i);
		}
		putchar('\n');
	}
	return 0;
}
