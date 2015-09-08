#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
static int bad_start;

bool isBadVersion(int version)
{
	return version >= bad_start;
}

class Solution {
public:
	int firstBadVersion(int n) {
		int l = 0, r = n;
		while (l != r-1) {
			// Which one is better?
			// const int mid = long(l+r)/2;
			const int mid = l/2+r/2+(l&r&1);
			if (isBadVersion(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return r;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 1; i <= 10; ++i) {
		bad_start = i;
		printf("%d\n", s.firstBadVersion(10));
	}
	return 0;
}
