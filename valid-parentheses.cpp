#include <string>
#include <stack>
using std::stack;
using std::string;

class Solution {
public:
	bool isValid(string s)
	{
		stack<char> parse_stack;
		parse_stack.push('^');

		for (char c: s) {
			switch (c) {
				case '(':
				case '[':
				case '{':
					parse_stack.push(c);
					break;
				case ')':
					if (parse_stack.top() == '(') {
						parse_stack.pop();
					} else {
						return 0;
					}
					break;
				case ']':
					if (parse_stack.top() == '[') {
						parse_stack.pop();
					} else {
						return 0;
					}
					break;
				case '}':
					if (parse_stack.top() == '{') {
						parse_stack.pop();
					} else {
						return 0;
					}
					break;
			}
		}

		return parse_stack.size() == 1;
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d", (int)s.isValid("()"    ));
	printf("%d", (int)s.isValid("()[]{}"));
	printf("%d", (int)s.isValid("(]"    ));
	printf("%d", (int)s.isValid("([)]"  ));
	printf("%d", (int)s.isValid("]"     ));
	putchar('\n');
	return 0;
}
