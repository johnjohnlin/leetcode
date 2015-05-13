#include <vector>
#include <cstdio>
#include <cassert>
#include <limits>
#include <functional>
using namespace std;

class Solution {
	typedef vector<int>::iterator Iter;
	static constexpr size_t MAX_SIZE_T = numeric_limits<size_t>::max();

	size_t min_length, cur_length;
	int sum;
	Iter first, last;

	void AdvanceFirst() {
		sum -= *first;
		++first;
		--cur_length;
	}
	void AdvanceLast() {
		sum += *last;
		++last;
		++cur_length;
	}
public:
	int minSubArrayLen(const int target, vector<int>& nums) {
		using std::placeholders::_1;

		// Special case
		const size_t n = nums.size();
		if (n == 0) {
			return 0;
		}

		first = last = nums.begin();
		min_length = MAX_SIZE_T;
		sum = 0;
		cur_length = 0;
		// Two pointer algorithm
		while (true) {
			// Expand tail
			assert(first <= last);
			while (sum < target) {
				if (last == nums.end()) {
					return min_length==MAX_SIZE_T? 0: min_length;
				} else {
					AdvanceLast();
				}
			}
			assert(first < last);
			// Shrink head
			while (sum >= target) {
				if (first == last) {
					assert(sum == 0);
					assert(cur_length == 0);
					if (last == nums.end()) {
						return 0;
					} else {
						++first;
						++last;
						break;
					}
				} else {
					min_length = min(min_length, cur_length);
					AdvanceFirst();
				}
			}
		}
		return 0;
	}
};

int main(int argc, char const* argv[])
{
	vector<int> v1{2,3,1,2,4,3};
	vector<int> v2{1,2,3,4,5};
	Solution s;
	printf("%d\n", s.minSubArrayLen(7, v1)); // 2
	printf("%d\n", s.minSubArrayLen(11, v2)); // 3
	return 0;
}
