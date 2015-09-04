#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	vector<pair<char, int>> buildBtStack(const string &p) {
		vector<pair<char, int>> ret;
		for (const char c: p) {
			if (c == '*') {
				ret.back().second = 0;
			} else {
				ret.emplace_back(c, -1);
			}
		}
		return ret;
	}
public:
	bool isMatch(const string &s, const string &p) {
		vector<pair<char, int>> bt_stack = buildBtStack(p);
		const size_t n_s = s.size(), n_bt = bt_stack.size();
		size_t i_s = 0, i_bt = 0;
		while (true) {
			while (i_bt < n_bt) {
				if (bt_stack[i_bt].second == -1) {
					// match character
					if (i_s < n_s and (bt_stack[i_bt].first == '.' or bt_stack[i_bt].first == s[i_s])) {
						++i_s;
						++i_bt;
					} else {
						break;
					}
				} else {
					// bypass *
					assert(bt_stack[i_bt].second == 0);
					++i_bt;
				}
			}
			// stops at the first mismatch or either pattern/target is matched
			if (i_s == n_s and i_bt == n_bt) {
				return true;
			}
			while (true) {
				// try to pop the pattern stack
				if (i_bt == 0) {
					return false;
				}
				--i_bt; // minus the index (pop) in advance owing to cleaner index
				if (bt_stack[i_bt].second == -1) {
					// normal character, just pop
					assert(i_s != 0);
					--i_s;
				} else {
					if (i_s < n_s and (bt_stack[i_bt].first == '.' or bt_stack[i_bt].first == s[i_s])) {
						++bt_stack[i_bt].second; // increase match count
						++i_bt; // add back because it's matched, should not pop
						++i_s;
						break;
					} else {
						// cannot increase, pop
						i_s -= bt_stack[i_bt].second;
						bt_stack[i_bt].second = 0;
					}
				}
			}
		}
		assert(0);
		return false;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", int(s.isMatch("aa","a"))); // 0
	printf("%d\n", int(s.isMatch("aa","aa"))); // 1
	printf("%d\n", int(s.isMatch("aaa","aa"))); // 0
	printf("%d\n", int(s.isMatch("aa", "a*"))); // 1
	printf("%d\n", int(s.isMatch("aa", ".*"))); // 1
	printf("%d\n", int(s.isMatch("ab", ".*"))); // 1
	printf("%d\n", int(s.isMatch("aab", "c*a*b"))); // 1
	printf("%d\n", int(s.isMatch("ab", ".*c"))); // 0
	printf("%d\n", int(s.isMatch("aaba", "ab*a*c*a*"))); // 0
	printf("%d\n", int(s.isMatch("a", "ab*"))); // 1
	printf("%d\n", int(s.isMatch("a", "ab*c*"))); // 1
	return 0;
}
