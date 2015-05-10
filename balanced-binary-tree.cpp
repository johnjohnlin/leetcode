#include <stack>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
public:
	bool isBalanced(TreeNode *root) {
		struct StackInfo {
			TreeNode *cur;
			HasDoneDirection state;
			int left_height;
		};
		if (root == nullptr) {
			return true;
		}
		// stack and return value
		int returned_height;
		stack<StackInfo> traverse_stack;
		traverse_stack.push({root, NEW_NODE, 0});
		while (traverse_stack.size() != 0) {
			TreeNode *cur = traverse_stack.top().cur;
			HasDoneDirection &state = traverse_stack.top().state;
			int &left_height = traverse_stack.top().left_height;
			// Traversal
			switch (state) {
				case NEW_NODE: {
					if (cur->left != nullptr) {
						traverse_stack.push({cur->left, NEW_NODE});
						state = DONE_LEFT;
						break;
					}
				}
				case DONE_LEFT: {
					left_height = returned_height;
					if (cur->right != nullptr) {
						traverse_stack.push({cur->right, NEW_NODE});
						state = DONE_RIGHT;
						break;
					}
				}
				case DONE_RIGHT: {
					int right_height = returned_height;
					right_height = cur->right == nullptr? 0: right_height;
					left_height = cur->left == nullptr? 0: left_height;
					printf("l=%d r=%d\n", left_height, right_height);
					if (abs(left_height - right_height) > 1) {
						return false;
					}
					returned_height = max(left_height, right_height) + 1;
					traverse_stack.pop();
				}
			}
		}
		return true;
	}
};

int main(int argc, char const* argv[])
{
	TreeNode tns[5];
	tns[0].val = 1; tns[0].left = tns + 1; tns[0].right = tns + 2;
	tns[1].val = 2; tns[1].left = nullptr; tns[1].right = tns + 4;
	tns[2].val = 2; tns[2].left = nullptr; tns[2].right = tns + 3;
	tns[3].val = 4; tns[3].left = nullptr; tns[3].right = nullptr;
	tns[4].val = 5; tns[4].left = nullptr; tns[4].right = nullptr;
	Solution s;
	printf("%d\n", (int)s.isBalanced(tns));
	return 0;
}
