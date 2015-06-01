#include <stack>
#include <vector>
#include <utility>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int trap(const vector<int>& heights) {
		stack<pair<int,int>> left_wall;
		int total_water = 0, water_level;
		for (int i = 0; i < heights.size(); ++i) {
			const int h = heights[i];
			while (not left_wall.empty()) {
				const int idx_left = left_wall.top().first;
				const int h_left = left_wall.top().second;
				const int water_w = i-idx_left-1;
				if (h >= h_left) {
					const int water_h = h_left - water_level;
					total_water += water_h * water_w;
					water_level = h_left;
					left_wall.pop();
				} else {
					const int water_h = h - water_level;
					assert(water_h >= 0 or water_w == 0); // if water_h < 0 then water_w == 0
					total_water += water_h * water_w;
					water_level = h;
					break;
				}
			}
			left_wall.emplace(i, h);
		}
		return total_water;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.trap(vector<int>{0,1,0,2,1,0,1,3,2,1,2,1})); // 6
	printf("%d\n", s.trap(vector<int>{4,2,3})); // 1
	return 0;
}
