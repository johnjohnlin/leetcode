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
	vector<Interval> insert(const vector<Interval>& intervals, const Interval newInterval) {
		vector<Interval> ret;
		const size_t n = intervals.size();
		if (n == 0) {
			ret.push_back(newInterval);
			return ret;
		}
		size_t i = 0;
		// can be improved to binary search time
		while (i < n and intervals[i].end < newInterval.start) {
			ret.push_back(intervals[i]);
			++i;
		}
		const int mid_start = (i==n)? newInterval.start: min(intervals[i].start, newInterval.start);
		while (i < n and intervals[i].start <= newInterval.end) {
			++i;
		}
		const int mid_end = max(intervals[i-1].end, newInterval.end);
		ret.emplace_back(mid_start, mid_end);
		while (i < n) {
			ret.push_back(intervals[i]);
			++i;
		}
		return ret;
	}
};

void PrintAns(const vector<Interval> &intervals)
{
	for (auto &interval: intervals) {
		printf("[%d, %d]\n", interval.start, interval.end);
	}
	puts("==");
}

int main(int argc, char const* argv[])
{
	Solution s;
	auto a1 = s.insert({{1,3},{6,9}}, {2,5});
	auto a2 = s.insert({{1,2},{3,5},{6,7},{8,10},{12,16}}, {4,9});
	PrintAns(a1);
	PrintAns(a2);
	return 0;
}
