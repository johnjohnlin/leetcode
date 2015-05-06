#include <stack>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
public:
	bool hasPathSum(TreeNode* root, int sum) {
		// A non-recursive method
		// Empty check
		if (root == nullptr) {
			return false;
		}
		// Start traversing
		stack<pair<TreeNode*, HasDoneDirection>> traverse_stack;
		traverse_stack.push({root, NEW_NODE});
		int path_sum = 0;
		while (traverse_stack.size() != 0) {
			TreeNode *cur = traverse_stack.top().first;
			HasDoneDirection &state = traverse_stack.top().second;
			// Traversal
			switch (state) {
				case NEW_NODE:
					path_sum += cur->val;
					if (cur->left == nullptr && cur->right == nullptr && path_sum == sum) {
						return true;
					}
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
					path_sum -= cur->val;
					traverse_stack.pop();
			}
		}
		return false;
	}
};

int main(int argc, char const* argv[])
{
	TreeNode tns[9];
	tns[0].val =  5; tns[0].left = tns + 1; tns[0].right = tns + 2;
	tns[1].val =  4; tns[1].left = tns + 3; tns[1].right = nullptr;
	tns[2].val =  8; tns[2].left = tns + 4; tns[2].right = tns + 5;
	tns[3].val = 11; tns[3].left = tns + 6; tns[3].right = tns + 7;
	tns[4].val = 13; tns[4].left = nullptr; tns[4].right = nullptr;
	tns[5].val =  4; tns[5].left = nullptr; tns[5].right = tns + 8;
	tns[6].val =  7; tns[6].left = nullptr; tns[6].right = nullptr;
	tns[7].val =  2; tns[7].left = nullptr; tns[7].right = nullptr;
	tns[8].val =  1; tns[8].left = nullptr; tns[8].right = nullptr;
	Solution s;
	printf("%d\n", (int)s.hasPathSum(tns, 22));
	printf("%d\n", (int)s.hasPathSum(tns, 5566));
	return 0;
}
