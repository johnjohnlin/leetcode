#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {'
		vector<string> ret;
		// Special case
		if (n == 0) {
			return ret;
		}
		// Start with (((...)))
		string s(string(n, '(')+string(n, ')'));
		// Backtracking loop
		while (true) {
			ret.push_back(s);
			// First we count how many () are at the tail.
			// For example       (((())))()()()()
			// will stop here          ^
			// Besides, we "clear" the '(' we met as well.
			// So it will become (((()))))))))))).
			size_t n_tail_pairs = 0, idx = 2*(n-1);
			while (n_tail_pairs < n && s[idx] == '(') {
				s[idx] = ')';
				n_tail_pairs += 1;
				idx -= 2;
			}
			if (n_tail_pairs == n) {
				// If it did not stop, then it's ()()()... and we are done
				return ret;
			} else {
				// Then we find the first '(' from the back.
				// (((())))))))))))
				//    ^
				while (s[idx] == ')') {
					--idx;
				}
				// and set to ')'
				// ((()))))))))))))
				s[idx] = ')';
				// Then we set the following characters to '('.
				// The length was already calculated.
				// ((()((((()))))))
				++idx;
				for (size_t i = idx; i <= idx+n_tail_pairs; ++i) {
					s[i] = '(';
				}
			}
		}
		assert(0);
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<string> ans;
	ans = s.generateParenthesis(3);
	for (auto &st: ans) {
		cout << st << endl;
	}
	return 0;
}
