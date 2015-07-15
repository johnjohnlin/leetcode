#include <algorithm>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	template<class Int> Int CeilDiv(Int a, Int b) {
		return (a-1)/b+1;
	}
public:
	int maximumGap(const vector<int>& nums) {
		struct Bin {
			int min_, max_;
			bool filled = false;
		};
		const int n = nums.size();
		if (n < 2) {
			return 0;
		}
		const auto minmax_it = minmax_element(nums.begin(), nums.end());
		const long long min_num = *minmax_it.first;
		const long long max_num = *minmax_it.second;
		const long long max_diff = (long long)max_num-min_num;
		if (max_diff <= 1) {
			return max_diff;
		}
		const long long maximum_gap_must_ge = CeilDiv<long>(max_diff, n-1); // Pigeonhole
		const long long bin_size = max(1ll, maximum_gap_must_ge-1); // Those in the same bin is impossible to be the answer
		const long long n_bin = max_diff/bin_size + 1;
		vector<Bin> bins(n_bin);
		for (int num: nums) {
			const long long bin_id = ((long long)num-min_num)/bin_size;
			auto &bin = bins.at(bin_id);
			if (bin.filled) {
				bin.max_ = max(bin.max_, num);
				bin.min_ = min(bin.min_, num);
			} else {
				bin.filled = true;
				bin.max_ = bin.min_ = num;
			}
		}
		int prev = min_num;
		int max_gap = 0;
		for (auto &bin: bins) {
			if (bin.filled) {
				max_gap = max(max_gap, bin.min_ - prev);
				prev = bin.max_;
			}
		}
		return max_gap;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.maximumGap({1,2,3,4,5,6,7,8,10,11,12,13}));
	printf("%d\n", s.maximumGap({1,1,1,1,1,1,1,1,2,3,4,5,6,7,10,11,12,13}));
	return 0;
}
