#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	string minWindow(const string &s, const string &t) {
		if (t.empty()) {
			return string();
		}
		const int N = numeric_limits<char>::max() + 1;
		bool care[N] = {};
		int left[N] = {};
		for (char c: t) {
			++left[c];
			care[c] = true;
		}
		int char_left = N - count(left, left+N, 0);
		size_t min_pos = 0;
		size_t min_len = s.size()+1;
		size_t pos = 0, len = 0;
		while (true) {
			if (char_left == 0) {
				// we have remove characters
				const int c = s[pos];
				if (care[c]) {
					if (left[c] == 0) {
						char_left += 1;
					}
					++left[c];
				}
				++pos;
				--len;
			} else {
				// we have to add characters
				if (pos+len == s.size()) {
					break;
				}
				++len;
				const int c = s[pos+len-1];
				if (care[c]) {
					--left[c];
					if (left[c] == 0) {
						char_left -= 1;
					}
				}
			}
			if (char_left == 0 and len < min_len) {
				min_len = len;
				min_pos = pos;
			}
		}
		return min_len == s.size()+1 ? string() : s.substr(min_pos, min_len);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
	printf("%s\n", s.minWindow("AA", "AA").c_str());
	return 0;
}
