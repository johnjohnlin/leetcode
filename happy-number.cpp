#include <cstdio>
#include <memory>

class Solution {
	static std::unique_ptr<bool[]> ishappy_table;
	static constexpr int ishappy_table_size = 9*9*3;

	int HappyNext(int i) {
		int next_happy = 0;
		while (i) {
			int q = i/10;
			int r = i-q*10;
			next_happy += r*r;
			i = q;
		}
		return next_happy;
	}

	bool prebuild() {
		// HappyNext(i) < table_size for all i table_size
		ishappy_table.reset(new bool[ishappy_table_size+1]);
		for (int i = 1; i < ishappy_table_size; ++i) {
			// If we repeat table_size+1 times but we do not meet 1
			// then there must be repeat series
			bool ishappy = false;
			for (int nrepeat = 0, ii = i; nrepeat <= ishappy_table_size; ++nrepeat) {
				if (ii == 1) {
					ishappy = true;
					break;
				}
				ii = HappyNext(ii);
			}
			ishappy_table[i] = ishappy;
		}
	}
public:
	bool isHappy(int n) {
		if (ishappy_table.get() == nullptr) {
			prebuild();
		}
		while (n > ishappy_table_size) {
			n = HappyNext(n);
		}
		return ishappy_table[n];
	}
};

std::unique_ptr<bool[]> Solution::ishappy_table;

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 0; i < 1000; ++i) {
		printf("%4d %d\n", i, (int)s.isHappy(i));
	}
	return 0;
}
