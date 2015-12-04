#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n < 2) {
			return 0;
		}
		vector<bool> removed(n, false);
		for (int i = 2; i*i < n; ++i) {
			if (removed[i]) {
				continue;
			}
			const int prime = i;
			for (int j = prime*prime; j < n; j += prime) {
				removed[j] = true;
			}
		}
		return count(removed.begin()+2, removed.end(), false);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 0; i < 100; ++i) {
		printf("%d %d\n", i, s.countPrimes(i));
	}
	return 0;
}
