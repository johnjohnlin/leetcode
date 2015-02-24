#include <stack>
#include <vector>
#include <string>
using std::stack;
using std::vector;
using std::string;
using std::stoi;

class Solution {
public:
	int evalRPN(const vector<string> &tokens)
	{
		stack<int> token_stack;
		for (const string &token: tokens) {
			if (token.size() != 1 || '0' <= token[0] && token[0] <= '9') {
				token_stack.push(stoi(token));
			} else {
				int b = token_stack.top();
				token_stack.pop();
				int a = token_stack.top();
				token_stack.pop();
				int result;

				switch (token[0]) {
					case '+':
						result = a+b;
						break;
					case '-':
						result = a-b;
						break;
					case '*':
						result = a*b;
						break;
					case '/':
						result = a/b;
						break;
				}

				token_stack.push(result);
			}
		}

		return token_stack.top();
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.evalRPN(vector<string>{{"2"}, {"1"}, {"+"}, {"3"}, {"*"}}));
	printf("%d\n", s.evalRPN(vector<string>{{"4"}, {"13"}, {"5"}, {"/"}, {"+"}}));
	printf("%d\n", s.evalRPN(vector<string>{{"0"}, {"3"}, {"/"}}));
	printf("%d\n", s.evalRPN(vector<string>{{"-1"}, {"1"}, {"*"}, {"-1"}, {"+"}}));
	return 0;
}
