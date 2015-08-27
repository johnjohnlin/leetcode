#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	vector<int> findOrder(const int numCourses, const vector<pair<int, int>>& prerequisites) {
		struct Vertex {
			vector<int> dependencies;
			bool done = false;
		};
		vector<Vertex> graph(numCourses);
		for (auto &p: prerequisites) {
			graph[p.first].dependencies.push_back(p.second);
		}

		vector<int> course_order;
		for (int not_found_count = 0, i = 0;;) {
			if (not_found_count == numCourses) {
				return (course_order.size()==numCourses)? course_order: vector<int>();
			}
			bool can_progress;
			if (graph[i].done) {
				can_progress = false;
			} else {
				can_progress = true;
				for (int d: graph[i].dependencies) {
					if (!graph[d].done) {
						can_progress = false;
						break;
					}
				}
			}
			if (can_progress) {
				course_order.push_back(i);
				graph[i].done = true;
				not_found_count = 0;
			} else {
				++not_found_count;
			}
			++i;
			if (i == numCourses) {
				i = 0;
			}
		}
		assert(0);
		return vector<int>();
	}
};

inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
}

int main(int argc, char const* argv[])
{
	Solution s;
	PrintVector(s.findOrder(4, vector<pair<int,int>>{{1,0},{2,0},{3,1},{3,2}}));
	return 0;
}
