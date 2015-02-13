#include <string>
#include <cstdio>
#include <algorithm>
using std::string;
using std::max;
using std::fill;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int last_occurence_record[128] = {};
		fill(last_occurence_record, last_occurence_record+128, -1);
		int bound_index = -1; // start point of valid string cannot \le this bound
		int max_length = 0;
		for (int i = 0; i < s.size(); ++i) {
			const char c = s[i];
			const int last_occurence = last_occurence_record[c];
			max_length = max(max_length, i-max(last_occurence, bound_index));
			bound_index = max(last_occurence, bound_index);
			last_occurence_record[c] = i;
		}
		return max_length;
    }
};

int main()
{
	Solution s;
	s.lengthOfLongestSubstring(string(""));
	s.lengthOfLongestSubstring(string("b"));
	s.lengthOfLongestSubstring(string("bbbbb"));
	s.lengthOfLongestSubstring(string("abcabcbb"));
	return 0;
}
