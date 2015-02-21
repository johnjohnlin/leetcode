#include <cstdio>
#include <vector>
using std::vector;

class Solution {
public:
	int findMin(const vector<int> &num)
	{
		if (num.size() == 1 || num.front() < num.back()) {
			return num[0];
		}

		int left = 0;
		int right = num.size()-1;

		while (right - left > 1) {
			int middle = (left + right) / 2;

			if (num[middle] < num[right]) {
				right = middle;
			} else /* if (num[middle] > num[left]) */ {
				left = middle;
			}
		}

		return num[right];
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.findMin(vector<int>{1}));
	printf("%d\n", s.findMin(vector<int>{3, 4, 5}));
	printf("%d\n", s.findMin(vector<int>{13, 12, 11}));
	printf("%d\n", s.findMin(vector<int>{105, 106, 101, 102, 103, 104}));
	return 0;
}
