#include <cstdio>

class Solution {
public:
	int trailingZeroes(int n)
	{
		int num_five = 0;

		do {
			n /= 5;
			num_five += n;
		} while (n);

		return num_five;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 0; i < 10; i++) {
		printf("%d", s.trailingZeroes(i));
	}
	return 0;
}
