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
		vector<int> citation_count(n+1, 0);
		for (const int citation: citations) {
			++citation_count[min(citation, n)];
		}
		for (int num_paper = n, accumulate_citation = 0; num_paper >= 0; --num_paper) {
			accumulate_citation += citation_count[num_paper];
			if (accumulate_citation >= num_paper) {
				return num_paper;
			}
		}
		assert(0);
		return 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.hIndex(vector<int>{3,1,0,5,6})); // 3
	return 0;
}
