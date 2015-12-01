#include "template_matrix.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
#include <functional>
using namespace std;

using std::placeholders::_1;
class Solution {
public:
	vector<int> findMinHeightTrees(const int n, const vector<pair<int, int>>& edges) {
		if (n == 1) {
			return vector<int>{0};
		}
		vector<vector<int>> neighbors(n);
		for (auto &edge: edges) {
			neighbors[edge.first ].push_back(edge.second);
			neighbors[edge.second].push_back(edge.first );
		}
		vector<int> wavefront;
		vector<int> visiting_count(n);
		for (int i = 0; i < n; ++i) {
			if (neighbors[i].size() == 1) {
				wavefront.push_back(i);
			}
			visiting_count[i] = neighbors[i].size();
		}

		int n_left = n;
		while (n_left > 2) {
			n_left -= wavefront.size();
			vector<int> wavefront_next;
			// PrintVector(wavefront);
			for (int src: wavefront) {
				auto &dsts = neighbors[src];
				for (int dst: dsts) {
					if (visiting_count[dst] > 1) {
						--visiting_count[dst];
						if (visiting_count[dst] == 1) {
							// all dependencies are met, emit it
							wavefront_next.push_back(dst);
						}
					}
				}
			}
			swap(wavefront, wavefront_next);
		}
		assert(all_of(visiting_count.begin(), visiting_count.end(), bind(equal_to<int>(), _1, 1)));
		return wavefront;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	PrintVector(s.findMinHeightTrees(6, {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}));
	PrintVector(s.findMinHeightTrees(1, {{}}));
	return 0;
}
