#include <string>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
class Solution {
public:
	bool wordBreak(const string s, const unordered_set<string>& wordDict) {
		vector<bool> dp_table(s.size(), false);
		for (int i = 0; i < s.size(); ++i) {
			for (const string &word: wordDict) {
				const int l = word.size();
				const int check_position = i+1-l;
				if (check_position >= 0) {
					const bool can_form_prev = check_position == 0 or dp_table[check_position-1];
					if (can_form_prev and equal(word.begin(), word.end(), s.begin()+check_position)) {
						dp_table[i] = true;
						break;
					}
				}
			}
		}
		return dp_table.back();
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", int(s.wordBreak("leetcode", {"leet", "code"}))); // 1
	printf("%d\n", int(s.wordBreak("leetcode", {"l", "tcode", "e"}))); // 1
	printf("%d\n", int(s.wordBreak("leetcode", {"l", "code", "e"}))); // 0
	return 0;
}
