#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using std::vector;
using std::copy;
using std::plus;
using std::bind1st;
using std::transform;

class Solution {
public:
	static const vector<int> gray_table;
	vector<int> grayCode(int order)
	{
		const int n = 1<<order;
		vector<int> gray(n);

		if (n <= gray_table.size()) {
			copy(gray_table.begin(), gray_table.begin()+n, gray.begin());
		} else {
			copy(gray_table.begin(), gray_table.end(), gray.begin());
			int n_done = gray_table.size();

			while (n_done != n) {
				transform(gray.begin(), gray.begin()+n_done, gray.rend()-2*n_done, bind1st(plus<int>(), n_done));
				n_done *= 2;
			}
		}

		return gray;
	}
};

const vector<int> Solution::gray_table {
	0, 1, 3, 2, 6, 7, 5, 4,
	12, 13, 15, 14, 10, 11, 9, 8
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int x: s.grayCode(3)) {
		printf("%d\n", x);
	}
	puts("==\n");

	for (int x: s.grayCode(5)) {
		printf("%d\n", x);
	}
	puts("==\n");

	for (int x: s.grayCode(6)) {
		printf("%d\n", x);
	}
	puts("==\n");
	return 0;
}
