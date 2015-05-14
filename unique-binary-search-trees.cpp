#include <vector>
#include <cstdio>
#include <numeric>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> v(n+1);
		v[0] = 1;
		for (int i = 1; i <= n; ++i) {
			v[i] = inner_product(v.begin(), v.begin()+i, v.rend()-i, 0);
		}
		return v.back();
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", s.numTrees(i));
	}
	return 0;
}
