#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string ret;
		while (n) {
			--n;
			const int q = n/26;
			const int r = n-q*26;
			ret.push_back('A'+r);
			n = q;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 1; i < 30; ++i) {
		puts(s.convertToTitle(i).c_str());
	}
	return 0;
}
