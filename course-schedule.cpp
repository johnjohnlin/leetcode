#include <string>
#include <vector>
#include <utility>
#include <limits>
#include <stack>
#include <cassert>
#include <cstdio>
using namespace std;

inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
}

class Solution {
public:
	bool canFinish(int numCourses, const vector<pair<int, int>>& prerequisites) {
		struct GraphNode {
			vector<int> out_edges_;
			int num_dependencies = 0;
		};

		vector<GraphNode> vertice(numCourses);
		vector<int> vertice_without_in;

		{ // make has_in a local vector

		vector<bool> has_in(numCourses, false);
		for (auto &p: prerequisites) {
			const int src = p.first;
			const int dst = p.second;
			if (src == dst) {
				return false;
			}
			vertice[src].out_edges_.push_back(dst);
			++(vertice[dst].num_dependencies);
			has_in[dst] = true;
		}
		for (size_t i = 0; i < has_in.size(); ++i) {
			if (!has_in[i]) {
				vertice_without_in.push_back(i);
			}
		}

		}

		for (int i = 0; i < vertice_without_in.size(); ++i) {
			stack<int> bfs_stack;
			bfs_stack.push(vertice_without_in[i]);
			while (bfs_stack.size() != 0) {
				const int cur = bfs_stack.top();
				bfs_stack.pop();
				for (int cur_out: vertice[cur].out_edges_) {
					assert(vertice[cur_out].num_dependencies != 0);
					--vertice[cur_out].num_dependencies;
					if (vertice[cur_out].num_dependencies == 0) {
						bfs_stack.push(cur_out);
					}
				}
			}
		}
		for (auto &vertex: vertice) {
			if (vertex.num_dependencies != 0) {
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", (int)s.canFinish(2,{{0,1}})); // 1
	printf("%d\n", (int)s.canFinish(2,{{0,1},{1,0}})); // 0
	printf("%d\n", (int)s.canFinish(3,{{0,1},{0,2},{1,2}})); // 1
	return 0;
}
