#include <string>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		char st_map[128] = {};
		char ts_map[128] = {};
		for (size_t i = 0; i < s.size(); ++i) {
			char &st_char = st_map[s[i]];
			char &ts_char = ts_map[t[i]];
			if (ts_char == 0 && st_char == 0) {
				st_char = t[i];
				ts_char = s[i];
			} else if (st_char != t[i]) {
				return false;
			} else {
				assert(ts_char == s[i]);
			}
		}
		return true;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", (int)s.isIsomorphic("foo", "bar")); // 0
	printf("%d\n", (int)s.isIsomorphic("aa", "ab")); // 0
	printf("%d\n", (int)s.isIsomorphic("egg", "foo")); // 1
	printf("%d\n", (int)s.isIsomorphic("paper", "title")); // 1
	return 0;
}
