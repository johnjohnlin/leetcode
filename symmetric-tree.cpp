#include <stack>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
	bool StructureDifferent(TreeNode *p, TreeNode *q)
	{
		return (p == nullptr) != (q == nullptr);
	}
public:
	bool isSymmetric(TreeNode *root) {
		struct StackInfo {
			TreeNode *master, *slave;
			HasDoneDirection state;
		};
		if (root == nullptr) {
			return true;
		}
		stack<StackInfo> traverse_stack;
		traverse_stack.push({root, root, NEW_NODE});
		while (traverse_stack.size() != 0) {
			TreeNode *cur_master = traverse_stack.top().master;
			TreeNode *cur_slave = traverse_stack.top().slave;
			HasDoneDirection &state = traverse_stack.top().state;
			// Traversal
			switch (state) {
				case NEW_NODE:
					if (cur_master->val != cur_slave->val) {
						return false;
					}
					if (StructureDifferent(cur_master->left, cur_slave->right)) {
						return false;
					}
					if (cur_master->left != nullptr) {
						traverse_stack.push({cur_master->left, cur_slave->right, NEW_NODE});
						state = DONE_LEFT;
						break;
					}
				case DONE_LEFT:
					if (StructureDifferent(cur_master->right, cur_slave->left)) {
						return false;
					}
					if (cur_master->right != nullptr) {
						traverse_stack.push({cur_master->right, cur_slave->left, NEW_NODE});
						state = DONE_RIGHT;
						break;
					}
				case DONE_RIGHT:
					traverse_stack.pop();
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
	printf("%d\n", (int)s.isSymmetric(tns));
	tns[1].right = tns[2].right = nullptr;
	printf("%d\n", (int)s.isSymmetric(tns));
	return 0;
}
