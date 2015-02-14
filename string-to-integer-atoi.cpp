#include <cstdlib>
#include <string>
#include <climits>
using std::string;

class Solution {
public:
	int atoi(string str) {
		// assume int is 32 bit, 2 complemnt
		size_t i = 0;

		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
			++i;
		}

		bool negative = false;
		if (str[i] == '+') {
			++i;
		} else if (str[i] == '-') {
			negative = !negative;
			++i;
		}

		int val = 0;
		int one = negative? -1: 1;
		int bound = negative? INT_MIN: INT_MAX;

		for (; i < str.size(); ++i) {
			if (str[i] < '0' || str[i] > '9') {
				break;
			}
			int digit = str[i] - '0';

			// overflow detection
			if (val > INT_MAX/10 || val < INT_MIN/10) {
				return bound;
			}

			val = val * 10 + one * digit;

			// overflow detection
			int overflow_bit = (val^one) & 0x80000000;
			if (overflow_bit != 0 && val != 0) {
				return bound;
			}
		}
		return val;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;

	printf("%d\n", s.atoi(string("123")));
	printf("%d\n", s.atoi(string("-9")));
	printf("%d\n", s.atoi(string("2147483648")));
	printf("%d\n", s.atoi(string("+0")));
	printf("%d\n", s.atoi(string("-0")));
	printf("%d\n", s.atoi(string("+1")));
	printf("%d\n", s.atoi(string("-1")));
	printf("%d\n", s.atoi(string("+-2")));
	printf("%d\n", s.atoi(string("    10522545459")));

	return 0;
}
