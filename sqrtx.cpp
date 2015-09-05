#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
class Solution {
	int clog2(int x) {
		int ret = 0;
		const int lut[] = {
			0,1,2,2,3,3,3,3,
			4,4,4,4,4,4,4,4
		};
		if (x >> 16) {
			x >>= 16;
			ret += 16;
		}
		if (x >> 8) {
			x >>= 8;
			ret += 8;
		}
		if (x >> 4) {
			x >>= 4;
			ret += 4;
		}
		return ret + lut[x];
	}
public:
	int mySqrt(int x) {
		const int a = x;
		if (x > 46340*46340) {
			return 46340;
		} else if (x <= 1) {
			return x;
		}
		const int l = clog2(x);
		x = (1<<(l/2)) | ((l&1)<<(l/2-1));
		x = min(46340, x);
		if (a > (1<<8)) {
			x -= (x*x-a)/(x*2);
		}
		if (a > (1<<12)) {
			x -= (x*x-a)/(x*2);
		}
		if (a > (1<<20)) {
			x -= (x*x-a)/(x*2);
		}
		while (x*x > a) {
			--x;
		}
		return x;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int x = 0; x <= 100; ++x) {
		printf("sqrt(%d) = %d\n", x, s.mySqrt(x));
	}
	return 0;
}
