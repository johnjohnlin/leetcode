#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 0) {
			return 0;
		}

		int passed_min_price = prices[0];
		int overall_max_profit = 0;

		for (int i = 1; i < prices.size(); ++i) {
			int current_max_profit = prices[i] - passed_min_price;

			overall_max_profit = max(current_max_profit, overall_max_profit);
			passed_min_price = min(prices[i], passed_min_price);
		}

		return overall_max_profit;
	}
};

int main(int argc, char const* argv[])
{
	;
	return 0;
}
