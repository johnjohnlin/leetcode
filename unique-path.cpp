#include <cstdio>
int C(int m, int n)
{
	int c = 1;
	if(m-n < n) {
		n = m-n;
	}
	for (int i = 0; i < n; ++i) {
		// c' = c*a/b, where a = (m-i), b = (i+1), but c*a will overflow
		// c = pb+q
		// c' = pa+qa/b (less possible to oveflow)
		const int a = m-i;
		const int b = i+1;
		const int p = c/b;
		const int q = c-p*b;
		c = p*a + q*a/b;
	}
	return c;
}

class Solution {
public:
	int uniquePaths(int m, int n) {
		--m; --n;
		return C(m+n, n);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.uniquePaths(1, 1));
	printf("%d\n", s.uniquePaths(1, 2));
	printf("%d\n", s.uniquePaths(2, 1));
	printf("%d\n", s.uniquePaths(2, 2));
	printf("%d\n", s.uniquePaths(51, 9));
	return 0;
}
