#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>
#include <cassert>
#include <cstdio>

using namespace std;

inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
}

inline void PrintMatrix(const vector<vector<int>> &m) {
	for (auto &v: m) {
		PrintVector(v);
	}
	puts("====");
}

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() <= 1) {
			ret.push_back(nums);
			return ret;
		}
		sort(nums.begin(), nums.end());
		while (true) {
			ret.push_back(nums);
			for (int i = nums.size()-2; ; --i) {
				if (nums[i] < nums[i+1]) {
					reverse(nums.begin()+i+1, nums.end());
					for (int j = i; ; ++j) {
						if (nums[j] > nums[i]) {
							swap(nums[i], nums[j]);
							break;
						}
					}
					break;
				} else if (i == 0) {
					return ret;
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
	vector<int> v{1,2,1};
	PrintMatrix(s.permuteUnique(v));
	return 0;
}
