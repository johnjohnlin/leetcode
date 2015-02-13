#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
using std::vector;
using std::sort;
using std::pair;

class Solution {
public:
	typedef pair<int, int> PII;
	typedef vector<int> VI;

	static inline VI return_sorted_pair(vector<PII> &numbers_with_indices, const int l, const int r) {
		const int x = numbers_with_indices[l].second;
		const int y = numbers_with_indices[r].second;
		return x < y? VI{{x, y}}: VI{{y, x}};
	}

	VI twoSum(VI &numbers, const int target) {
		vector<PII> numbers_with_indices(numbers.size());
		for (int i = 0; i < numbers.size(); ++i) {
			numbers_with_indices[i] = PII(numbers[i], i+1);
		}
		sort(numbers_with_indices.begin(), numbers_with_indices.end(), [](PII x, PII y) -> bool {
			return x.first < y.first;
		});
		// copy back
		for (int i = 0; i < numbers.size(); ++i) {
			numbers[i] = numbers_with_indices[i].first;
		}

		int l = 0, r = numbers.size() - 1;
		bool move_r = true;
		while (true) {
			if (move_r) {
				const int cur_target = target - numbers[l];
				while (l < r && numbers[r] >= cur_target) {
					if (cur_target == numbers[r]) {
						return return_sorted_pair(numbers_with_indices, l, r);
					}
					--r;
				}
			} else {
				const int cur_target = target - numbers[r];
				while (l < r && numbers[l] <= cur_target) {
					if (cur_target == numbers[l]) {
						return return_sorted_pair(numbers_with_indices, l, r);
					}
					++l;
				}
			}
			move_r = !move_r;
		}
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	vector<int> v1{{2, 7, 11, 15}};
	vector<int> v2{{5, 75, 25}};
	auto sol1 = s.twoSum(v1, 9);
	printf("%d %d\n", sol1[0], sol1[1]);
	auto sol2 = s.twoSum(v2, 100);
	printf("%d %d\n", sol2[0], sol2[1]);
	return 0;
}
