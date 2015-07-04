#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		--k;
		string ret;
		vector<int> factorial_stack{1};
		vector<char> candidate(n);
		iota(begin(candidate), end(candidate), '1');
		for (int i = 1; i < n; ++i) {
			factorial_stack.push_back(factorial_stack.back()*i);
		}
		while (not factorial_stack.empty()) {
			const int d = factorial_stack.back();
			const int q = k/d;
			const int r = k-q*d;
			auto qth_it = candidate.begin()+q;
			ret.push_back(*qth_it);
			candidate.erase(qth_it);
			k = r;
			factorial_stack.pop_back();
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 1; i <= 40; ++i) {
		printf("%s\n", s.getPermutation(5, i).c_str());
	}
	return 0;
}
