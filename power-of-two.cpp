#include <cstdio>

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 and (n&(n-1)) == 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = -10; i < 10; ++i) {
		printf("%5d%5d\n", i, int(s.isPowerOfTwo(i)));
	}
	return 0;
}
