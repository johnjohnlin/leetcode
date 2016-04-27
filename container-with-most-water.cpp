#include "template_matrix.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int maxArea(const vector<int>& height) {
		if (height.empty()) {
			return 0;
		}
		int max_area = 0;
		int i = 0, j = height.size()-1;
		while (i < j) {
			const int hi = height[i];
			const int hj = height[j];
			max_area = max((j-i)*min(hi,hj), max_area);
			i += int(hi <= hj);
			j -= int(hi >= hj);
		}
		return max_area;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.maxArea({1,2,4,3}));
	return 0;
}
