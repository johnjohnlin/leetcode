#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area_no_overlap = (C-A)*(D-B)+(G-E)*(H-F);
		if (E >= C or A >= H or B >= H or F >= D) {
			return area_no_overlap;
		} else {
			int xs[] = {A, C, E, G};
			int ys[] = {B, D, F, H};
			sort(begin(xs), end(xs));
			sort(begin(ys), end(ys));
			return area_no_overlap - (xs[2]-xs[1])*(ys[2]-ys[1]);
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
	return 0;
}
