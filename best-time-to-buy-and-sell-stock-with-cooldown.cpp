#include "template_matrix.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int maxProfit(const vector<int>& prices) {
		size_t n = prices.size();
		if (n < 2) {
			return 0;
		}
		int max_profit_when_last_is_sell = 0;
		int max_profit = 0;
		int cooldown[3] = {};
		for (size_t i = 1; i < n; ++i) {
			max_profit_when_last_is_sell = max(cooldown[0], max_profit_when_last_is_sell)+prices[i]-prices[i-1];
			cooldown[0] = max(cooldown[0], cooldown[1]);
			cooldown[1] = cooldown[2];
			cooldown[2] = max_profit_when_last_is_sell;
			max_profit = max(max_profit_when_last_is_sell, max_profit);
		}
		return max_profit;
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.maxProfit({1, 2})); // 1
	printf("%d\n", s.maxProfit({2, 1})); // 0
	printf("%d\n", s.maxProfit({1, 2, 3, 0, 2})); // 3
	printf("%d\n", s.maxProfit({0, 100, 99, 200})); // 200
	printf("%d\n", s.maxProfit({0, 100, 99, 200, -100, 9900})); // 10100
	return 0;
}
