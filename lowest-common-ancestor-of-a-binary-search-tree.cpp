#include "template_tree.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		const int smaller = min(p->val, q->val);
		const int larger = max(p->val, q->val);
		stack<TreeNode*> s;
		while (true) {
			s.push(root);
			if (root->val == smaller) {
				break;
			} else {
				root = (root->val < smaller)? root->right: root->left;
			}
		}
		TreeNode *ret = s.top();
		while (not s.empty()) {
			if (s.top()->val > ret->val and s.top()->val <= larger) {
				ret = s.top();
			}
			s.pop();
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	TreeNode tns[9];
	tns[0].val = 6; tns[0].left = tns + 1; tns[0].right = tns + 2;
	tns[1].val = 2; tns[1].left = tns + 3; tns[1].right = tns + 4;
	tns[2].val = 8; tns[2].left = tns + 5; tns[2].right = tns + 6;
	tns[3].val = 0; tns[3].left = nullptr; tns[3].right = nullptr;
	tns[4].val = 4; tns[4].left = tns + 7; tns[4].right = tns + 8;
	tns[5].val = 7; tns[5].left = nullptr; tns[5].right = nullptr;
	tns[6].val = 9; tns[6].left = nullptr; tns[6].right = nullptr;
	tns[7].val = 3; tns[7].left = nullptr; tns[7].right = nullptr;
	tns[8].val = 5; tns[8].left = nullptr; tns[8].right = nullptr;
	printf("%d\n", s.lowestCommonAncestor(tns, tns+2, tns+1)->val);
	printf("%d\n", s.lowestCommonAncestor(tns, tns+4, tns+1)->val);
	return 0;
}
