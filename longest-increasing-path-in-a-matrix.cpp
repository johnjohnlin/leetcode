#include "template_matrix.h"
#include "template_tree.h"
#include "template_list.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
#include <queue>
using namespace std;
class Solution {
public:
	int longestIncreasingPath(const vector<vector<int>>& matrix) {
		const int h = matrix.size();
		if (h == 0) return 0;
		const int w = matrix[0].size();
		if (w == 0) return 0;
		vector<int> num_in(w*h, 0);
		queue<pair<int,int>> q, nq;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				int nin = 0;
				int cur = matrix[y][x];
				if (x-1 >= 0) { nin += cur < matrix[y][x-1]; }
				if (x+1 <  w) { nin += cur < matrix[y][x+1]; }
				if (y-1 >= 0) { nin += cur < matrix[y-1][x]; }
				if (y+1 <  h) { nin += cur < matrix[y+1][x]; }
				num_in[w*y+x] = nin;
				if (nin == 0) {
					q.emplace(y,x);
				}
			}
		}
		int l = 0;
		while (not q.empty()) {
			while (not q.empty()) {
				pair<int,int> curpos = q.front();
				q.pop();
				int y = curpos.first;
				int x = curpos.second;
				int cur = matrix[y][x];
#define WALK(y, x)\
	int &nin = num_in[w*(y)+(x)];\
	if (cur > matrix[y][x] and nin > 0) {\
		--nin;\
		if (nin == 0) {\
			nq.emplace(y, x);\
		}\
	}
				if (x-1 >= 0) { WALK(y,x-1); }
				if (x+1 <  w) { WALK(y,x+1); }
				if (y-1 >= 0) { WALK(y-1,x); }
				if (y+1 <  h) { WALK(y+1,x); }
#undef WALK
			}
			++l;
			swap(q, nq);
		}
		return l;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.longestIncreasingPath({
		{9,9,4},
		{6,6,8},
		{2,1,1}
	}));
	printf("%d\n", s.longestIncreasingPath({
		{3,4,5},
		{3,2,6},
		{2,2,1}
	}));
	return 0;
}
