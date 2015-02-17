#include <cstdio>

class Solution {
public:
	bool isPalindrome(int x)
	{
		if (x < 10) {
			return x >= 0;
		} else {
			int upper = x;
			int upper_prev; // used for detect odd and even
			int lower_reversed = 0;
			while (true) {
				int quotient = upper/10;
				int residue = upper - quotient*10;
				upper_prev = upper;
				upper = quotient;
				if (lower_reversed == 0 && residue == 0) {
					return false;
				}
				lower_reversed = lower_reversed*10 + residue;

				if (upper == lower_reversed || upper_prev == lower_reversed) {
					return true;
				} else if (upper <= lower_reversed) {
					return false;
				}
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", int(s.isPalindrome(-1)));
	printf("%d\n", int(s.isPalindrome(0)));
	printf("%d\n", int(s.isPalindrome(4)));
	printf("%d\n", int(s.isPalindrome(10)));
	printf("%d\n", int(s.isPalindrome(44)));
	printf("%d\n", int(s.isPalindrome(4334)));
	printf("%d\n", int(s.isPalindrome(25252)));
	printf("%d\n", int(s.isPalindrome(252521)));
	printf("%d\n", int(s.isPalindrome(413)));
	printf("%d\n", int(s.isPalindrome(1904091)));
	return 0;
}
