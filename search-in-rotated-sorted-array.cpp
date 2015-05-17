#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int search(const vector<int> &num, const int target)
	{
		if (num.size() == 1) {
			return num[0] == target? 0: -1;
		}
		if (num.front() < num.back()) {
			auto it = lower_bound(num.begin(), num.end(), target);
			if (it == num.end() or *it != target) {
				return -1;
			} else {
				return it-num.begin();
			}
		}

		int left = 0;
		int right = num.size()-1;
		while (right - left != 1) {
			int middle = (left + right) / 2;
			if (num[middle] < num[right]) {
				right = middle;
			} else /* if (num[middle] > num[left]) */ {
				left = middle;
			}
		}
		int search_l, search_r;
		if (num.back() >= target) {
			search_l = right;
			search_r = num.size();
		} else {
			search_l = 0;
			search_r = right;
		}
		auto it = lower_bound(num.begin()+search_l, num.begin()+search_r, target);
		if (it == num.begin()+search_r or *it != target) {
			return -1;
		} else {
			return it-num.begin();
		}

		return 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{105, 106, 101, 102, 103, 104};
	for (int i = 100; i <= 107; ++i) {
		printf("%d, %d\n", i, s.search(v, i));
	}
	return 0;
}
