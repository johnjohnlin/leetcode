#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class MedianFinder {
	priority_queue<int,vector<int>,less<int>> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	size_t n = 0;
	int tmp; // used for n = 1
public:
	void addNum(int num) {
		switch (n) {
			case 0:
				tmp = num;
				break;
			case 1:
				max_heap.push(min(num, tmp));
				min_heap.push(max(num, tmp));
				break;
			default:
				if (num > max_heap.top()) {
					min_heap.push(num);
				} else {
					max_heap.push(num);
				}
				// balance two heaps
				if (min_heap.size() > max_heap.size()) {
					assert(min_heap.size() == max_heap.size()+1);
					max_heap.push(min_heap.top());
					min_heap.pop();
				}
				if (max_heap.size() > min_heap.size()+1) {
					assert(max_heap.size() == min_heap.size()+2);
					min_heap.push(max_heap.top());
					max_heap.pop();
				}
				assert(
					max_heap.size() == min_heap.size()+1 or
					max_heap.size() == min_heap.size()
				);
		}
		++n;
	}
	double findMedian() {
		if (n == 1) {
			return tmp;
		}
		if (n%2 == 0) {
			return (max_heap.top() + min_heap.top()) * 0.5;
		} else {
			return max_heap.top();
		}
	}
};

int main(int argc, char const* argv[])
{
	MedianFinder mf;
	mf.addNum(1);
	mf.addNum(2);
	printf("%lf\n", mf.findMedian());
	mf.addNum(3);
	printf("%lf\n", mf.findMedian());
	return 0;
}
