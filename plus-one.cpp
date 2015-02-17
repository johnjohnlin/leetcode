#include <cstdio>
#include <vector>
using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits)
	{
		vector<int> plus1_ans = digits;

		int carry = 1;
		for (auto it = plus1_ans.rbegin(); it != plus1_ans.rend(); ++it) {
			*it += carry;
			carry = 0;
			if (*it >= 10) {
				*it -= 10;
				carry = 1;
			}
		}

		if (carry) {
			plus1_ans.push_back(0);
			plus1_ans[0] = 1;
		}

		return plus1_ans;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;

	vector<int> v1{1, 2, 1, 3};
	auto ans1 = s.plusOne(v1);
	for (int d: v1) {
		printf("%d", d);
	}
	putchar('\n');
	for (int d: ans1) {
		printf("%d", d);
	}
	putchar('\n');

	vector<int> v2{9, 9};
	auto ans2 = s.plusOne(v2);
	for (int d: v2) {
		printf("%d", d);
	}
	putchar('\n');
	for (int d: ans2) {
		printf("%d", d);
	}
	putchar('\n');

	return 0;
}
