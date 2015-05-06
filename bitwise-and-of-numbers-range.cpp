#include <cstdio>
#include <cassert>
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
#if 0
		// method 1
		int ret = 0;
		for (int i = 0; i < 32; i++) {
			int thisbit_and_result = (m&n&1) && ((m&~1) == (n&~1));
			ret |= thisbit_and_result << i;
			m >>= 1;
			n >>= 1;
		}
		return ret;
#else
		// method 2
		int mask = m^n;
		mask |= mask>>1;
		mask |= mask>>2;
		mask |= mask>>4;
		mask |= mask>>8;
		mask |= mask>>16;
		assert((m&~mask) == (n&~mask)); // mask1 is the different part of m and n
		return m&~mask;
#endif
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.rangeBitwiseAnd(5, 7));
	printf("%d\n", s.rangeBitwiseAnd(2, 3));
	printf("%d\n", s.rangeBitwiseAnd(2, 2));
	return 0;
}
