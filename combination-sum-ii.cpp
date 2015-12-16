#include "template_matrix.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, const int target) {
		const size_t n = remove_if(candidates.begin(), candidates.end(), bind(greater<int>(), placeholders::_1, target))-candidates.begin();
		candidates.resize(n);
		sort(candidates.begin(), candidates.end());
		int sum = 0;
		vector<vector<int>> ret;
		vector<size_t> bt_idx_stack;
		bool just_pop = false;
		if (n == 0) {
			return ret;
		}

		sum += candidates[0];
		bt_idx_stack.push_back(0);
		while (true) {
			if (sum >= target) {
				if (sum == target) {
					ret.emplace_back(bt_idx_stack.size());
					transform(
						bt_idx_stack.begin(), bt_idx_stack.end(), ret.back().begin(),
						[&](const size_t idx){ return candidates[idx]; }
					);
				}
				sum -= candidates[bt_idx_stack.back()];
				bt_idx_stack.pop_back();
				just_pop = true;
				continue;
			}

			if (just_pop) {
				if (bt_idx_stack.empty()) {
					return ret;
				}
				size_t &idx = bt_idx_stack.back();
				sum -= candidates[idx];
				while (true) {
					++idx;
					if (idx == n) {
						bt_idx_stack.pop_back();
						break;
					}
					if (candidates[idx] > candidates[idx-1]) {
						sum += candidates[idx];
						just_pop = false;
						break;
					}
				}
			} else {
				const size_t pushme = bt_idx_stack.back() + 1;
				if (pushme >= n) {
					sum -= candidates[bt_idx_stack.back()];
					bt_idx_stack.pop_back();
					just_pop = true;
				} else {
					bt_idx_stack.push_back(pushme);
					sum += candidates[pushme];
				}
			}
		}
		assert(0);
		return vector<vector<int>>();
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{10,1,2,7,6,1,5};
	vector<int> v2{3,1,3,5,1,1};
	vector<int> v3{1,1,2,2,2,3,4,4,4};
	vector<int> v4{14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
	PrintMatrix(s.combinationSum2(v1, 8));
	PrintMatrix(s.combinationSum2(v2, 8));
	PrintMatrix(s.combinationSum2(v3, 6));
	// PrintMatrix(s.combinationSum2(v4, 27));
	return 0;
}
