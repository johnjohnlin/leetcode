#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;

int Gcd(int a, int b)
{
	int gcd = 1;
	while (a != b) {
		const bool a_even = a%2 == 0;
		const bool b_even = b%2 == 0;
		if (a_even and b_even) {
			gcd *= 2;
			a /= 2;
			b /= 2;
		} else if (a_even) {
			a /= 2;
		} else if (b_even) {
			b /= 2;
		} else {
			if (a > b) {
				a = (a-b)/2;
			} else {
				b = (b-a)/2;
			}
		}
	}
	return gcd * a;
}

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		const int n = nums.size();
		k %= n;
		if (k == 0) {
			return;
		}
		const int gcd = Gcd(n, k);
		// Cache unfriendly...
		for (int i = 0; i < gcd; ++i) {
			for (int j = 0, idx = i, replaced = nums[idx]; j < n/gcd; ++j) {
				idx += k;
				if (idx >= n) {
					idx -= n;
				}
				swap(replaced, nums[idx]);
			}
		}
	}
};

inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
}

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{1,2,3,4,5,6,7};
	vector<int> v2{1};
	s.rotate(v1, 3);
	s.rotate(v2, 0);
	PrintVector(v1);
	PrintVector(v2);
	return 0;
}
