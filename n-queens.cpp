#include <functional>
#include <algorithm>
#include <memory>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
class Solution {
	static const int PASSED = -1;
	vector<string> GenerateCheckboard(const int *solution, const int n) {
		vector<string> checkboard(n, string(n, '.'));
		for (int i = 0; i < n; ++i) {
			checkboard[i][solution[i]] = 'Q';
		}
		return checkboard;
	}
	int CheckSolution(const int *solution, bool *bin_filled, const int n) {
		int error_line1 = n, error_line2 = n;
		fill_n(&bin_filled[0], n*2-1, false);
		for (int i = 0; i < n; ++i) {
			const int bin_id = i+solution[i];
			if (bin_filled[bin_id]) {
				error_line1 = i;
				break;
			}
			bin_filled[bin_id] = true;
		}
		fill_n(&bin_filled[0], n*2-1, false);
		for (int i = 0; i < n; ++i) {
			const int bin_id = i-solution[i]+n-1;
			if (bin_filled[bin_id]) {
				error_line2 = i;
				break;
			}
			bin_filled[bin_id] = true;
		}
		return min(error_line1, error_line2);
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ret;
		unique_ptr<int[]> solution(new int[n]);
		unique_ptr<bool[]> bin_filled(new bool[n*2-1]);
		iota(&solution[0], &solution[n], 0);
		do {
			const int first_error_line = CheckSolution(solution.get(), bin_filled.get(), n);
			if (first_error_line == n) {
				ret.push_back(GenerateCheckboard(&solution[0], n));
			} else {
				sort(&solution[first_error_line+1], &solution[n], greater<int>());
			}
		} while(next_permutation(&solution[0], &solution[n]));
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	int n = 4;
	auto ans = s.solveNQueens(n);
	for (auto &sol: ans) {
		for (auto &line: sol) {
			printf("%s\n", line.c_str());
		}
		puts(string(n, '=').c_str());
	}
	return 0;
}
