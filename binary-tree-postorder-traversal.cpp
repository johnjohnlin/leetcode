#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
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
	vector<int> postorderTraversal(TreeNode* root) {
		// A non-recursive method
		vector<int> ret;
		if (root == nullptr) {
			return ret;
		}
		stack<pair<TreeNode*, HasDoneDirection>> traverse_stack;
		traverse_stack.push({root, NEW_NODE});
		while (traverse_stack.size() != 0) {
			int depth = traverse_stack.size() - 1;
			TreeNode *cur = traverse_stack.top().first;
			HasDoneDirection &state = traverse_stack.top().second;
			// Traversal
			switch (state) {
				case NEW_NODE:
					// add current node to answer
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
					ret.push_back(cur->val);
					traverse_stack.pop();
			}
		}
		return ret;
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
	auto &&ans = s.postorderTraversal(tns);
	for (auto v: ans) {
		printf("%d ", v);
	}
	putchar('\n');
	return 0;
}
