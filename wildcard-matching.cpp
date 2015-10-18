#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	string RemoveAdjacentAsterisk(const string &p_in) {
		string p;
		bool prev_is_asterisk = false;
		for (char c: p_in) {
			if (c != '*' or not prev_is_asterisk) {
				p.push_back(c);
			}
			prev_is_asterisk = c == '*';
		}
		return p;
	}
public:
	bool isMatch(const string &s, const string &p_in) {
		const string p = RemoveAdjacentAsterisk(p_in);
		const size_t n = p.size();
		vector<size_t> src{0};
		for (size_t i = 0; i < n and p[i] == '*'; ++i) {
			src.push_back(i+1);
		}
		bool can_reach_last = src.back() == n;
		for (char c: s) {
			vector<char> reachable_dst(n+1, 0); // bool is slower
			vector<size_t> dst;
			for (size_t sid: src) {
				const bool any_length = p[sid] == '*';
				const bool can_advance = p[sid] == '?' or p[sid] == '*' or p[sid] == c;
				if (sid != n and can_advance) {
					const size_t dst_start = sid + size_t(not any_length);
					if (not reachable_dst[dst_start]) {
						reachable_dst[dst_start] = true;
						dst.push_back(dst_start);
					}
					for (size_t i = dst_start; i < n and p[i] == '*' and not reachable_dst[i+1]; ++i) {
						reachable_dst[i+1] = true;
						dst.push_back(i+1);
					}
				}
			}
			if (dst.size() == 0) {
				return false;
			}
			swap(src, dst);
			can_reach_last = reachable_dst.back();
		}
		return can_reach_last;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", int(s.isMatch("aa","a"))); // 0
	printf("%d\n", int(s.isMatch("aa","aa"))); // 1
	printf("%d\n", int(s.isMatch("aaa","aa"))); // 0
	printf("%d\n", int(s.isMatch("aa", "*"))); // 1
	printf("%d\n", int(s.isMatch("aa", "a*"))); // 1
	printf("%d\n", int(s.isMatch("ab", "?*"))); // 1
	printf("%d\n", int(s.isMatch("aab", "c*a*b"))); // 0
	printf("%d\n", int(s.isMatch("", "*"))); // 1
	printf("%d\n", int(s.isMatch("c", "*?*"))); // 1
	return 0;
}
