#include <cstdio>

class Solution {
public:
	double pow(double x, int n)
	{
		double product = 1.0;
		double powx_of_2 = n<0 ? 1.0/x : x;
		if (n < 0) {
			n = -n;
		}

		while (n) {
			if (n & 1) {
				product *= powx_of_2;
			}
			n /= 2;
			powx_of_2 *= powx_of_2;
		}
		return product;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%lf\n", s.pow(3.0, 7));
	return 0;
}
