#include <cstdio>
#include <cmath>

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		// 1. Determine which one is longer
		int *array_short, *array_long;
		int size_short, size_long;
		if (m < n) {
			array_short = A;
			size_short = n;
			array_long = B;
			size_long = m;
		} else {
			array_long = A;
			size_long = n;
			array_short = B;
			size_short = m;
		}
		bool has_2_median = (n+m)%2 == 0;

		const int n_elements_median_must_larger_than = (m+n-1)/2;

		// 2. We determine whether the median value
		// "GT the largest one" or "LT the smallest one" in the short one
		if (n != m && array_short[size_short-1] <= array_long[size_long-2-n_elements_median_must_larger_than]) {
			const int idx = n_elements_median_must_larger_than-n_short;
			if (has_2_median) {
				return array_long[idx];
			} else {
				return (double(array_long[idx]) + return array_long[idx])*0.5;
			}
		}
		if (array_short[0] >= array_long[n_elements_median_must_larger_than]) {
			// median < array_short[0]
			if (has_2_median) {
				return array_long[idx];
			} else if (n == m) {
				return (double(array_long[idx]) + array_short[0])*0.5;
			} else {
				return (double(array_long[idx]) + min(array_long[idx+1], array_short[0]))*0.5;
			}
		}

		// 3. In the short array?
		int begin_short = 0;
		int end_short = size_short-1;
		while (true) {
		}

		// 4. In the long array?

		// 5. This should not happen
		return NAN;
	}
};

int main(int argc, char const* argv[])
{
	int A[] = {1, 2, 3, 4};
	int B[] = {1, 4, 5, 7, 8};
	Solution s;
	printf("%d\n", s.findMedianSortedArrays(A, 4, B, 5));
	printf("%d\n", s.findMedianSortedArrays(A, 4, B+2, 3));
	return 0;
}
