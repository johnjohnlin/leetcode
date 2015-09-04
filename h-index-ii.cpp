#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int hIndex(const vector<int>& citations) {
		const int n = citations.size();
		int l = 0, r = n;
		while (l != r) {
			const int mid = (l+r)/2;
			const int n_paper = n-mid;
			if (n_paper <= citations[mid]) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		return n-l;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.hIndex(vector<int>{9,9,9,9,9})); // 5
	printf("%d\n", s.hIndex(vector<int>{0,9,9,9,9})); // 4
	printf("%d\n", s.hIndex(vector<int>{0,0,9,9,9})); // 3
	printf("%d\n", s.hIndex(vector<int>{0,0,3,3,3})); // 3
	printf("%d\n", s.hIndex(vector<int>{0,0,0,9,9})); // 2
	printf("%d\n", s.hIndex(vector<int>{0,0,0,0,9})); // 1
	printf("%d\n", s.hIndex(vector<int>{0,0,0,0,0})); // 0
	printf("%d\n", s.hIndex(vector<int>{})); // 0
	return 0;
}
