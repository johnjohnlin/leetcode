#include <algorithm>
#include <vector>
#include <functional>
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
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0) {
			return vector<int>();
		}
		int slide_window_size = 1;
		while (slide_window_size != k) {
			const int stride = min(k-slide_window_size, slide_window_size);
			transform(
				nums.begin()+stride, nums.end(),
				nums.begin(), nums.begin(), (const int&(*)(const int&, const int&))max<int>
			);
			slide_window_size += stride;
			assert(slide_window_size <= k);
		}
		nums.resize(nums.size()-k+1);
		return nums;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{1,3,-1,-3,5,3,6,7};
	auto ans = s.maxSlidingWindow(v1, 3);
	PrintVector(ans);
	return 0;
}
