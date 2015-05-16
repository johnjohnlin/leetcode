#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
#ifdef USE_STL
		return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
#else
		int first = 0, last = nums.size();
		while (first != last) {
			const int mid = (first+last)/2;
			if (nums[mid] < target) {
				first = mid+1;
			} else {
				last = mid;
			}
		}
		return first;
#endif
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{1,3,5,6};
	printf("%d\n", s.searchInsert(v, 0)); // 0
	printf("%d\n", s.searchInsert(v, 2)); // 1
	printf("%d\n", s.searchInsert(v, 5)); // 2
	printf("%d\n", s.searchInsert(v, 7)); // 4
	return 0;
}
