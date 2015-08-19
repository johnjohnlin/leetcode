#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	inline void KeepDiv(int &num, const int b) {
		int q;
		while (true) {
			q = num/b;
			if (num != q*b) {
				break;
			}
			num = q;
		}
	}
public:
	bool isUgly(int num) {
		if (num < 1) {
			return false;
		}
		KeepDiv(num, 2);
		KeepDiv(num, 3);
		KeepDiv(num, 5);
		return num == 1;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 1; i <= 100; ++i) {
		printf("%d %d\n", i, int(s.isUgly(i)));
	}
	return 0;
}
