#include <string>
#include <algorithm>
#include <utility>
#include <memory>
#include <vector>
#include <stack>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		unique_ptr<int[]> longest_when_end_with(new int[s.size()]);
		stack<int> index_stack;
		int max_length = 0;
		for (int i = 0; i < s.size(); ++i) {
			const char c = s[i];
			switch (c) {
				case '(':
					longest_when_end_with[i] = 0;
					index_stack.push(i);
					break;
				case ')':
					if (index_stack.size() >= 1) {
						int left = index_stack.top();
						int valid_length = i-left+1;
						index_stack.pop();
						valid_length += (left==0)? 0: longest_when_end_with[left-1];
						longest_when_end_with[i] = valid_length;
						max_length = max(max_length, valid_length);
					} else {
						longest_when_end_with[i] = 0;
					}
					break;
			}
		}
		return max_length;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.longestValidParentheses("(()")); // 2
	printf("%d\n", s.longestValidParentheses(")()())")); // 4
	printf("%d\n", s.longestValidParentheses("(()()")); // 4
	return 0;
}
