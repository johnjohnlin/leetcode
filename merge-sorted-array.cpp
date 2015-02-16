#include <algorithm>
#include <cstdio>
using std::copy;

class Solution {
public:
	void merge(int A[], int m, int B[], int n)
	{
		int *a = A+n;
		int *b = B;
		int *c = A;
		int a_left = m;
		int b_left = n;
		copy(A, A+m, a);

		while (a_left != 0 && b_left != 0) {
			if (*a < *b) {
				*c = *a;
				++a;
				--a_left;
			} else {
				*c = *b;
				++b;
				--b_left;
			}
			++c;
		}

		if (a_left != 0) {
			copy(a, a+a_left, c);
		}

		if (b_left != 0) {
			copy(b, b+b_left, c);
		}
	}
};

int main(int argc, char const* argv[])
{
	const int M = 5;
	const int N = 4;
	const int M_PLUS_N = M+N;
	int A[M_PLUS_N] = {-4, 2, 3, 4, 90};
	int B[N] = {1, 3, 79, 100};
	Solution s;
	s.merge(A, M, B, N);
	for (int i = 0; i < M_PLUS_N; ++i) {
		printf("%d\n", A[i]);
	}
	return 0;
}
