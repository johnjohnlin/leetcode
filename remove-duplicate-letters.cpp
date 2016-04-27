#include <string>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(const string &s) {
		string ret, tmp;
		ret.reserve(26);
		int count[26] = {};
		bool must_add[26] = {};
		for (char c: s) {
			++count[c-'a'];
			must_add[c-'a'] = true;
		}
		for (char c: s) {
			const int ci = c-'a';
			--count[ci];
			if (not must_add[ci]) {
				continue;
			}
			while (not ret.empty() and count[ret.back()-'a'] != 0 and ret.back() >= c) {
				must_add[ret.back()-'a'] = true;
				ret.pop_back();
			}
			ret.push_back(c);
			must_add[ci] = false;
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	puts(s.removeDuplicateLetters("bcabc").c_str()); // abc
	puts(s.removeDuplicateLetters("abcab").c_str()); // abc
	puts(s.removeDuplicateLetters("abacab").c_str()); // abc
	puts(s.removeDuplicateLetters("bacab").c_str()); // acb
	puts(s.removeDuplicateLetters("babcab").c_str()); // abc

	puts(s.removeDuplicateLetters("acbdabc").c_str()); // abdc
	puts(s.removeDuplicateLetters("abcdabc").c_str()); // abcd
	puts(s.removeDuplicateLetters("acbcdabc").c_str()); // abcd
	puts(s.removeDuplicateLetters("abcbdabc").c_str()); // abcd
	puts(s.removeDuplicateLetters("bddbccd").c_str()); // bcd
	return 0;
}
