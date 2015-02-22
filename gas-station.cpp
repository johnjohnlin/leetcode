#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using std::vector;
using std::transform;
using std::minus;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		const int n = gas.size();

		vector<int> net(n);
		std::transform(gas.begin(), gas.end(), cost.begin(), net.begin(), minus<int>());

		int prefix_sum = net[0];
		int min_prefix_sum = net[0];
		int min_index = 0;
		for (int i = 1; i < n; ++i) {
			prefix_sum += net[i];
			if (prefix_sum < min_prefix_sum) {
				min_prefix_sum = prefix_sum;
				min_index = i;
			}
		}

		if (prefix_sum < 0) {
			return -1;
		} else {
			min_index += 1;
			return min_index == n? 0: min_index;
		}
	}
};

int main(int argc, char const* argv[])
{
	// vector<int> gas = {0, 3, 0, 0, 0, 0, 4};
	// vector<int> cost = {1, 1, 1, 1, 1, 1, 1};
	vector<int> gas = {2, 0, 1, 2, 3, 4, 0};
	vector<int> cost = {0, 1, 0, 0, 0, 0, 11};
	Solution s;
	printf("%d\n", s.canCompleteCircuit(gas, cost));
	return 0;
}
