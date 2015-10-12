#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int largestRectangleArea(const vector<int>& height) {
		// if go across .first (index), the rectangle cannot be higher than .second
		stack<pair<int,int>> limitations; limitations.push({-1,0});
		const int n = height.size();
		int max_area = 0;
		for (int i = 0; i <= n; ++i) {
			const int h = (i == n)? 0: height[i]; // 0 for poping all elements in the end
			while (limitations.top().second > h) {
				const int maxh = limitations.top().second;
				limitations.pop();
				const int j = limitations.top().first;
				max_area = max(maxh*(i-j-1), max_area);
			}
			limitations.push({i,h});
		}
		return max_area;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.largestRectangleArea({2,1,5,6,2,3}));
	printf("%d\n", s.largestRectangleArea({100}));
	return 0;
}
