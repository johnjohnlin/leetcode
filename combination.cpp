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
	vector<int> bt_stack_;
public:
	vector<vector<int>> combine(const int n, const int k) {
		vector<vector<int>> ret;
		if (k == 0 || n < k) {
			return ret;
		}
		bt_stack_.resize(k);

		// backtracing init
		iota(bt_stack_.begin(), bt_stack_.end(), 1);
		// backtracing loop
		while (true) {
			ret.push_back(bt_stack_);
			int reset_pos = k-1;
			while (reset_pos-(k-1)+n == bt_stack_[reset_pos]) {
				if (reset_pos == 0) {
					return ret;
				}
				--reset_pos;
			}
			++(bt_stack_[reset_pos]);
			iota(bt_stack_.begin()+reset_pos, bt_stack_.end(), bt_stack_[reset_pos]);
		}
		assert(0);
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	PrintMatrix(s.combine(5,3));
	PrintMatrix(s.combine(4,2));
	return 0;
}
