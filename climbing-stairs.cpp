#include <cstdio>

class Solution {
public:
	int climbStairs(int n)
	{
		if (n == 1) {
			return 1;
		}
		int previous_value[2] = {1, 1};
		int fibonacci;
		for (int i = 1; i < n; ++i) {
			fibonacci = previous_value[0] + previous_value[1];
			previous_value[1] = previous_value[0];
			previous_value[0] = fibonacci;
		}
		return fibonacci;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 1; i < 10; ++i) {
		printf("%d\n", s.climbStairs(i));
	}
	return 0;
}
