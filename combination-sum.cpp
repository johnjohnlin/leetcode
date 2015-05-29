#include <vector>
#include <cstdio>
#include <functional>
#include <algorithm>
#include <cassert>
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
	void PushToTarget(const int pushed_idx, const int pushed_val) {
		while (sum_ < target_) {
			sum_ += pushed_val;
			bt_val_stack_.push_back(pushed_val);
			bt_idx_stack_.push_back(pushed_idx);
		}
		if (sum_ == target_) {
			ret_.push_back(bt_val_stack_);
		}
		sum_ -= pushed_val;
		bt_val_stack_.pop_back();
		bt_idx_stack_.pop_back();
		assert(sum_ < target_);
	}
	vector<int> bt_val_stack_;
	vector<int> bt_idx_stack_;
	vector<vector<int>> ret_;
	int sum_;
	int target_;

	void SortAndRemove(vector<int>& A) {
		using std::placeholders::_1;
		auto new_last = remove_if(A.begin(), A.end(), bind(greater<int>(), _1, target_));
		A.resize(new_last-A.begin());
		sort(A.begin(), A.end());
	}
	void PopStackUntilNot(const int x) {
		while (bt_idx_stack_.size() != 0 && bt_idx_stack_.back() == x) {
			sum_ -= bt_val_stack_.back();
			bt_idx_stack_.pop_back();
			bt_val_stack_.pop_back();
		}
	}

public:

	vector<vector<int>> combinationSum(vector<int>& candidates, const int target) {
		target_ = target;
		SortAndRemove(candidates);
		vector<vector<int>> ret;
		if (candidates.size() == 0) {
			return ret;
		}
		const int n = candidates.size();
		sum_ = 0;

		// backtracing init
		PushToTarget(0, candidates[0]);
		// backtracing loop
		while (true) {
			assert(bt_idx_stack_.size() == bt_val_stack_.size());
			PopStackUntilNot(n-1);
			assert(bt_idx_stack_.size() == bt_val_stack_.size());
			if (bt_idx_stack_.size() == 0) {
				swap(ret, ret_);
				return ret;
			}
			int &idx = bt_idx_stack_.back();
			const int old_val = candidates[idx];
			++idx;
			const int new_val = candidates[idx];
			bt_val_stack_.back() = new_val;
			sum_ = sum_ - old_val + new_val;
			PushToTarget(idx, new_val);
		}
		assert(0);
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{2,3,6,7};
	vector<int> v2{700};
	PrintMatrix(s.combinationSum(v1, 7));
	PrintMatrix(s.combinationSum(v2, 7));
	return 0;
}
