#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cassert>
using namespace std;

class Solution {
	template <class T> int QueueRoutine(T& pq, const vector<int>& nums, const int k)
	{
		const int n = nums.size();
		for (int i = 0; i < k; ++i) {
			pq.push(nums[i]);
		}
		for (int i = k; i < n; ++i) {
			pq.push(nums[i]);
			pq.pop();
		}
		return pq.top();
	}
public:
	int findKthLargest(vector<int>& nums, int k) {
		const int n = nums.size();
		if (k < n/2) {
			priority_queue<int, vector<int>, greater<int>> pq;
			return QueueRoutine(pq, nums, k);
		} else {
			priority_queue<int, vector<int>> pq;
			return QueueRoutine(pq, nums, n+1-k);
		}
		assert(0);
		return 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v{3,2,1,5,6,4};
	for (int i = 1; i <= v.size(); ++i) {
		printf("%d\n", s.findKthLargest(v, i));
	}
	return 0;
}
