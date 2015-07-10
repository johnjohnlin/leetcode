#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int ret = 0;
		int head = n, tail = 0, ofs = 1;
		while(head != 0) {
			const int d = head/10;
			const int r = head-d*10;
			head = d;
			tail += ofs*r;
			int left = tail-ofs+1;
			left = min(ofs, max(0, left));
			ret += head*ofs + left;
			ofs *= 10;
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.countDigitOne(13)); // 6
	return 0;
}
