#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
	struct StackData {
		int value_, cur_min_;
	};
	stack<StackData> stack_;
public:
	int top() {
		return stack_.top().value_;
	}
	int getMin() {
		return stack_.top().cur_min_;
	}
	void push(int x) {
		if (stack_.size() == 0) {
			stack_.push({x, x});
		} else {
			const int prev_min = getMin();
			stack_.push({x, min(prev_min, x)});
		}
	}
	void pop() {
		stack_.pop();
	}
};

int main(int argc, char const* argv[])
{
	MinStack s;
	s.push(1);
	printf("%d %d\n", s.getMin(), s.top());
	s.push(3);
	printf("%d %d\n", s.getMin(), s.top());
	s.push(0);
	printf("%d %d\n", s.getMin(), s.top());
	s.push(2);
	printf("%d %d\n", s.getMin(), s.top());
	return 0;
}
