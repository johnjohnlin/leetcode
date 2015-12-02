class Queue {
	stack<int> input_, output_;
	void reverse() {
		if (output_.empty()) {
			while (not input_.empty()) {
				output_.push(input_.top());
				input_.pop();
			}
		}
	}
public:
	// Push element x to the back of queue.
	void push(int x) {
		input_.push(x);
	}
	// Removes the element from in front of queue.
	void pop(void) {
		reverse();
		output_.pop();
	}
	// Get the front element.
	int peek(void) {
		reverse();
		return output_.top();
	}
	// Return whether the queue is empty.
	bool empty(void) {
		reverse();
		return output_.empty();
	}
};
