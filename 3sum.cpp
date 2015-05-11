#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> triples;
		size_t n = nums.size();
		if (n < 3) {
			return triples;
		}
		sort(nums.begin(), nums.end());
		size_t i = 0;
		while (true) {
			size_t j = i+1;
			size_t k = n-1;
			// Tighten [j,k] interlacingly
			while (true) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum >= 0) {
					if (sum == 0) {
						triples.push_back({nums[i], nums[j], nums[k]});
					}
					// Find the next different element
					const int curk = nums[k];
					while (nums[k] == curk) {
						--k;
						if (j == k) {
							goto no_more_jk;
						}
					}
				} else if (sum < 0) {
					// Find the next different element
					const int curj = nums[j];
					while (nums[j] == curj) {
						++j;
						if (j == k) {
							goto no_more_jk;
						}
					}
				}
			}
			no_more_jk:
			// Find the next different element
			const int curi = nums[i];
			while (nums[i] == curi) {
				++i;
				if (i+2 == n) {
					goto no_more_i;
				}
			}
		}
		no_more_i:

		return triples;
	}
};

int main(int argc, char const* argv[])
{
	vector<int> v{-1,0,1,2,-1,-4};
	Solution s;
	auto&& ans = s.threeSum(v);
	for (auto&& triple: ans) {
		for (auto v: triple) {
			printf("%d,", v);
		}
		putchar('\n');
	}
	return 0;
}
