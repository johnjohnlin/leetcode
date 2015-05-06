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
	bool NoNodeCheck(TreeNode *p, TreeNode *q)
	{
		return (p == nullptr) == (q == nullptr);
	}
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		// A non-recursive method
		if (p == nullptr && q == nullptr) {
			return true;
		}
		if (!NoNodeCheck(p, q)) {
			return false;
		}
		stack<pair<TreeNode*, HasDoneDirection>> traverse_stack_p;
		stack<pair<TreeNode*, HasDoneDirection>> traverse_stack_q;
		traverse_stack_p.push({p, NEW_NODE});
		traverse_stack_q.push({q, NEW_NODE});
		while (traverse_stack_p.size() != 0) { // Use p as master
			TreeNode *curp = traverse_stack_p.top().first;
			TreeNode *curq = traverse_stack_q.top().first;
			HasDoneDirection &state = traverse_stack_p.top().second;
			// Traversal
			switch (state) {
				case NEW_NODE:
					if (curp->val != curq->val) {
						return false;
					}
					if (!NoNodeCheck(curp->left, curq->left)) {
						return false;
					}
					if (curp->left != nullptr) {
						traverse_stack_p.push({curp->left, NEW_NODE});
						traverse_stack_q.push({curq->left, NEW_NODE});
						state = DONE_LEFT;
						break;
					}
				case DONE_LEFT:
					if (!NoNodeCheck(curp->right, curq->right)) {
						return false;
					}
					if (curp->right != nullptr) {
						traverse_stack_p.push({curp->right, NEW_NODE});
						traverse_stack_q.push({curq->right, NEW_NODE});
						state = DONE_RIGHT;
						break;
					}
				case DONE_RIGHT:
					traverse_stack_p.pop();
					traverse_stack_q.pop();
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
	tns[2].val = 3; tns[2].left = nullptr; tns[2].right = tns + 3;
	tns[3].val = 4; tns[3].left = nullptr; tns[3].right = nullptr;
	tns[4].val = 5; tns[4].left = nullptr; tns[4].right = nullptr;
	Solution s;
	printf("%d\n", (bool)s.isSameTree(tns, tns));
	printf("%d\n", (bool)s.isSameTree(tns, tns+1));
	return 0;
}
