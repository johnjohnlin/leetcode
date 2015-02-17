#include <cstdio>
#include <string>
using std::string;

class Solution {
public:
	int titleToNumber(string s)
	{
		int ans = 0;
		for (auto it = s.begin(); it != s.end(); ++it) {
			ans *= 26;
			ans += *it - 'A' + 1;
		}
		return ans;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.titleToNumber("A"));
	printf("%d\n", s.titleToNumber("ABZ"));
	printf("%d\n", s.titleToNumber("AC"));
	return 0;
}
