#include <climits>
#include <cstdio>

class Solution {
public:
	int reverse(int x)
	{
		int reversed_x = 0;
		while (x != 0) {
			const int quotient = x/10;
			const int residue = x-quotient*10;

			if (reversed_x > INT_MAX/10 || reversed_x < INT_MIN/10) {
				return 0;
			}
			reversed_x *= 10;
			reversed_x += residue;
			if (((reversed_x ^ residue) & 0x80000000) && residue != 0) {
				return 0;
			}

			x = quotient;
		}

		return reversed_x;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;

	printf("%d\n", s.reverse(135));
	printf("%d\n", s.reverse(-123));
	printf("%d\n", s.reverse(1534236469));
	printf("%d\n", s.reverse(-90100));
	return 0;
}
