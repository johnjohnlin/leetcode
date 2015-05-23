#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		static const char *ten[10] = {
			"",
			"3",
			"33",
			"333",
			"32",
			"2",
			"23",
			"233",
			"2333",
			"31",
		};
		static const char *roman_table = "??MDCLXVI";
		char buffer[32];
		int offset = 0;
		int digits[4];
		for (int i = 3; i >= 0; --i) {
			const int d = num/10;
			digits[i] = num-d*10;
			num = d;
		}
		for (int i = 0; i < 4; ++i) {
			for (const char *s = ten[digits[i]]; *s != '\0'; ++s) {
				const char roman = roman_table[i*2+(*s)-'1'];
				buffer[offset] = roman;
				++offset;
			}
		}
		buffer[offset] = '\0';
		return string(buffer);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%s\n", s.intToRoman(139).c_str());
	printf("%s\n", s.intToRoman(3999).c_str());
	return 0;
}
