#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		int prev, cur;
		auto it = prices.begin();
		if (it != prices.end()) {
			prev = *it;
			while (++it != prices.end()) {
				int cur = *it;
				result += max(cur-prev, 0);
				prev = cur;
			}
		}
		return result;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{1, 2, 3, 2, 3, 4};
	printf("%d\n", s.maxProfit(v));
	return 0;
}
