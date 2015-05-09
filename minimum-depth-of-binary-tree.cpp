#include <stack>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
public:
	int minDepth(TreeNode* root) {
		// A non-recursive method
		size_t min_depth = numeric_limits<size_t>::max();
		if (root == nullptr) {
			return 0;
		}
		stack<pair<TreeNode*, HasDoneDirection>> traverse_stack;
		traverse_stack.push({root, NEW_NODE});
		while (traverse_stack.size() != 0) {
			TreeNode *cur = traverse_stack.top().first;
			HasDoneDirection &state = traverse_stack.top().second;
			// Traversal
			switch (state) {
				case NEW_NODE:
					if (cur->left != nullptr) {
						traverse_stack.push({cur->left, NEW_NODE});
						state = DONE_LEFT;
						break;
					}
				case DONE_LEFT:
					if (cur->right != nullptr) {
						traverse_stack.push({cur->right, NEW_NODE});
						state = DONE_RIGHT;
						break;
					}
				case DONE_RIGHT:
					if (cur->left == nullptr && cur->right == nullptr) {
						min_depth = min(min_depth, traverse_stack.size());
					}
					traverse_stack.pop();
			}
		}
		return min_depth;
	}
};

int main(int argc, char const* argv[])
{
	TreeNode tns[5];
	tns[0].val = 1; tns[0].left = tns + 1; tns[0].right = tns + 2;
	tns[1].val = 2; tns[1].left = nullptr; tns[1].right = tns + 4;
	tns[2].val = 3; tns[2].left = nullptr; tns[2].right = tns + 3;
	tns[3].val = 4; tns[3].left = nullptr; tns[3].right = nullptr;
	tns[4].val = 5; tns[4].left = nullptr; tns[4].right = nullptr;
	Solution s;
	printf("%d\n", s.minDepth(tns));
	return 0;
}
