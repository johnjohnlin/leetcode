#include <cstdio>
#include <vector>
using std::vector;

class Solution {
public:
	int findPeakElement(const vector<int> &num)
	{
		int positive_slope_index = 0;
		int negative_slope_index = num.size();

		while (negative_slope_index - positive_slope_index > 1) {
			int middle_index = (positive_slope_index + negative_slope_index) / 2;

			if (num[middle_index-1] > num[middle_index]) {
				negative_slope_index = middle_index;
			} else {
				positive_slope_index = middle_index;
			}
		}

		return positive_slope_index;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.findPeakElement(vector<int>{1}));
	printf("%d\n", s.findPeakElement(vector<int>{1, 2}));
	printf("%d\n", s.findPeakElement(vector<int>{2, 1}));
	printf("%d\n", s.findPeakElement(vector<int>{1, 2, 1}));
	printf("%d\n", s.findPeakElement(vector<int>{3, 2, 1}));
	printf("%d\n", s.findPeakElement(vector<int>{1, 2, 3, 1}));
	printf("%d\n", s.findPeakElement(vector<int>{2, 1, 2}));
	return 0;
}
