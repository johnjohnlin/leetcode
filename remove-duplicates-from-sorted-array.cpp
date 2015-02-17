#include <cstdio>

class Solution {
public:
	int removeDuplicates(int A[], int n)
	{
		if (n <= 1) {
			return n;
		}

		int prev = A[0], count = 1;
		for (int i = 1; i < n; ++i) {
			if (prev != A[i]) {
				++count;
				A[count-1] = A[i];
			}
			prev = A[i];
		}
		return count;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	int array[] = {1, 1, 2, 3, 4, 4, 4, 6, 7};

	int num_left = s.removeDuplicates(array, sizeof(array)/sizeof(int));

	printf("%d:\n", num_left);
	for (int i = 0; i < num_left; ++i) {
		printf("%d\n", array[i]);
	}

	return 0;
}
