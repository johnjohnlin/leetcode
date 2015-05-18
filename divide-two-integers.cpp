#include <cstdio>
#include <limits>
#include <cassert>
using namespace std;

class Solution {
	void CalculateOneBit(unsigned &cur_dividend, unsigned &q, const unsigned shift_in, const unsigned divisor) {
		cur_dividend <<= 1;
		q <<= 1;
		cur_dividend |= shift_in;
		if (cur_dividend >= divisor) {
			cur_dividend -= divisor;
			q |= 1;
		}
	}
public:
	int divide(int dividend, int divisor) {
		const bool dividend_overflow = dividend == numeric_limits<int>::min();
		const bool divisor_overflow = divisor == numeric_limits<int>::min();
		if (divisor == 0) {
			return numeric_limits<int>::max();
		}
		if (divisor == 1) {
			return dividend;
		}
		if (divisor == -1) {
			return dividend_overflow? numeric_limits<int>::max(): -dividend;
		}
		if (divisor_overflow) {
			return dividend_overflow? 1: 0;
		}
		bool neg = false;
		if (dividend < 0) {
			dividend = -dividend;
			neg = !neg;
		}
		if (divisor < 0) {
			divisor = -divisor;
			neg = !neg;
		}
		unsigned cur_dividend = 0;
		unsigned q = 0;
		unsigned udivisor = divisor;
		for (int i = 31; i >= 0; --i) {
			CalculateOneBit(cur_dividend, q, (dividend>>i)&1, udivisor);
			assert(q >= 0);
		}
		return neg? -q: q;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.divide(30, 7));
	printf("%d\n", s.divide(30, -7));
	printf("%d\n", s.divide(-30, 7));
	printf("%d\n", s.divide(-30, -7));
	printf("%d\n", s.divide(-1, -1));
	printf("%d\n", s.divide(-2147483648, 2));
	printf("%d\n", s.divide(-2147483648, -1109186033));
	return 0;
}
