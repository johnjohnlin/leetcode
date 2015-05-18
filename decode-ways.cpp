#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(const string &s) {
		if (s.size() == 0 || s[0] == '0') {
			return 0;
		}
		int n_ways_prev = 1;
		int n_ways_cur = 1;
		for (size_t i = 1; i < s.size(); ++i) {
			// printf("'%c'\n", s[i]);
			if (s[i] == '0') {
				if (s[i-1] != '1' and s[i-1] != '2') {
					return 0;
				} else {
					n_ways_cur = n_ways_prev;
					n_ways_prev = 0;
				}
			} else if (s[i-1] == '1' or s[i-1] == '2' and '0' <= s[i] and s[i] <= '6') {
				int updated_cur = n_ways_cur + n_ways_prev;
				n_ways_prev = n_ways_cur;
				n_ways_cur = updated_cur;
			} else {
				n_ways_prev = n_ways_cur;
			}
			// printf("%d %d\n", n_ways_cur, n_ways_prev);
		}
		return n_ways_cur;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.numDecodings("0"));  // 0
	printf("%d\n", s.numDecodings("12")); // 2
	printf("%d\n", s.numDecodings("12120")); // 3
	return 0;
}
