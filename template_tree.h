#pragma once
#include <stack>
#include <utility>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class TreeTraversalHandler {
public:
	virtual void DoPreOrder(TreeNode *p, int depth) = 0;
	virtual void DoInOrder(TreeNode *p, int depth) = 0;
	virtual void DoPostOrder(TreeNode *p, int depth) = 0;
	virtual ~TreeTraversalHandler() {}
};

void TreeTraverse(TreeNode* root, TreeTraversalHandler *h) {
	// A non-recursive method
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
	if (root == nullptr) {
		return;
	}
	std::stack<std::pair<TreeNode*, HasDoneDirection>> traverse_stack;
	traverse_stack.push({root, NEW_NODE});
	while (traverse_stack.size() != 0) {
		int depth = traverse_stack.size() - 1;
		TreeNode *cur = traverse_stack.top().first;
		HasDoneDirection &state = traverse_stack.top().second;
		// Traversal
		switch (state) {
			case NEW_NODE:
				h->DoPreOrder(cur, depth);
				if (cur->left != nullptr) {
					traverse_stack.push({cur->left, NEW_NODE});
					state = DONE_LEFT;
					break;
				}
			case DONE_LEFT:
				h->DoInOrder(cur, depth);
				if (cur->right != nullptr) {
					traverse_stack.push({cur->right, NEW_NODE});
					state = DONE_RIGHT;
					break;
				}
			case DONE_RIGHT:
				h->DoPostOrder(cur, depth);
				traverse_stack.pop();
		}
	}
}
