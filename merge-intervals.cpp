#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;
		const int n = intervals.size();
		if (n == 0) {
			return ret;
		}
		sort(
			intervals.begin(), intervals.end(),
			[](const Interval &a, const Interval &b){ return a.start < b.start; }
		);
		ret.push_back(intervals[0]);
		for (int i = 1; i < n; ++i) {
			if (intervals[i].start <= ret.back().end) {
				ret.back().end = max(intervals[i].end, ret.back().end);
			} else {
				ret.emplace_back(intervals[i]);
			}
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<Interval> q1{{1,3},{2,6},{8,10},{15,18}};
	auto ans1 = s.merge(q1);
	for (auto&& a: ans1) {
		printf("%d~%d\n", a.start, a.end);
	}

	return 0;
}
