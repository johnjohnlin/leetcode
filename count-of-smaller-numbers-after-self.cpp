#include "template_matrix.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	typedef pair<int,int> PInt;
	pair<int,vector<int>> Ranking(const vector<int> &nums) {
		assert(not nums.empty());
		vector<PInt> idx_nums(nums.size());
		vector<int> ranks(nums.size());
		for (size_t i = 0; i < nums.size(); ++i) {
			idx_nums[i].first = i;
			idx_nums[i].second = nums[i];
		}
		// nums in ascending order
		sort(idx_nums.begin(), idx_nums.end(), [] (const PInt &a, const PInt &b) {
			return a.second < b.second;
		});
		int rank = 0;
		int last = idx_nums[0].second;
		for (size_t i = 0; i < nums.size(); ++i) {
			if (idx_nums[i].second != last) {
				last = idx_nums[i].second;
				++rank;
			}
			ranks[idx_nums[i].first] = rank;
		}
		return make_pair(rank, move(ranks));
	}
	vector<vector<int>> GenerateMipmap(int n) {
		vector<vector<int>> ret;
		while (n != 0) {
			ret.emplace_back(n, 0);
			n /= 2;
		}
		return ret;
	}
public:
	vector<int> countSmaller(const vector<int>& nums) {
		const size_t n = nums.size();
		vector<int> ret(n);
		if (nums.empty()) {
			return ret;
		}
		const auto r = Ranking(nums);
		const int max_rank = r.first;
		const vector<int> &ranks = r.second;
		vector<vector<int>> mipmap = GenerateMipmap(max_rank+1);
		for (size_t i = n-1;; --i) {
			// calculate
			int n_smaller = 0;
			for (int rank = ranks[i], l = 0; l < mipmap.size(); rank >>= 1, ++l) {
				if ((rank&1) != 0) {
					n_smaller += mipmap[l][rank-1];
				}
			}
			ret[i] = n_smaller;
			// update
			for (int rank = ranks[i], l = 0; l < mipmap.size(); rank >>= 1, ++l) {
				if (rank >= mipmap[l].size()) {
					break;
				}
				++(mipmap[l][rank]);
			}
			if (i == 0) {
				break;
			}
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	PrintVector(s.countSmaller({5,2,6,1}));
	return 0;
}
