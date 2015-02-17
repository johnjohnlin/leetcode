#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using std::vector;
using std::transform;
using std::plus;

class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		if (numRows <= 0) {
			return vector<vector<int>>();
		}

		vector<vector<int>> pascals(numRows);

		pascals[0].resize(1);
		pascals[0][0] = 1;

		for (int n = 2; n <= numRows; ++n) {
			vector<int> &previous_row = pascals[n-2];
			vector<int> &current_row = pascals[n-1];
			current_row.resize(n);
			current_row[0] = 1;
			current_row[n-1] = 1;
			transform(
				previous_row.begin(), previous_row.end()-1,
				previous_row.begin()+1,
				current_row.begin()+1,
				plus<int>()
			);
		}

		return pascals;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (auto& c: s.generate(4)) {
		for (int e: c) {
			printf("%d ", e);
		}
		putchar('\n');
	}
	return 0;
}
