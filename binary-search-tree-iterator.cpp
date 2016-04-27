#include "template_tree.h"
#include <stack>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class BSTIterator {
	stack<TreeNode*> st;
	void LeftMost(TreeNode *cur) {
		while (cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		}
	}
public:
	BSTIterator(TreeNode *root) {
		LeftMost(root);
	}
	bool hasNext() {
		return not st.empty();
	}
	int next() {
		TreeNode *cur = st.top();
		st.pop();
		LeftMost(cur->right);
		return cur->val;
	}
};

int main(int argc, char const* argv[])
{
	{
		TreeNode tn[] {{0}};
		BSTIterator it(tn+0);
		while (it.hasNext()) {
			printf("%d\n", it.next());
		}
		puts("===");
	}
	{
		TreeNode tn[] {{0},{1},{2},{3}};
		tn[3].left = tn+1;
			tn[1].left = tn+0;
			tn[1].right = tn+2;
		BSTIterator it(tn+3);
		while (it.hasNext()) {
			printf("%d\n", it.next());
		}
		puts("===");
	}
	return 0;
}
