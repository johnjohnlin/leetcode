#include "template_tree.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	class LCAFinder: public TreeTraversalHandler {
		TreeNode *p_, *q_;
		vector<bool> cur_path_;
		vector<bool> p_path_, q_path_;
	public:
		LCAFinder(TreeNode *p, TreeNode *q): p_(p), q_(q) {}
		virtual void DoPreOrder(TreeNode *n, int depth) {
			if (n == p_) {
				p_path_ = cur_path_;
			}
			if (n == q_) {
				q_path_ = cur_path_;
			}
			cur_path_.push_back(false);
		}
		virtual void DoInOrder(TreeNode *n, int depth) {
			cur_path_.back() = true;
		}
		virtual void DoPostOrder(TreeNode *n, int depth) {
			cur_path_.pop_back();
		}
		vector<bool> GetLcaPath() {
			if (p_path_.size() >= q_path_.size()) {
				auto qp_end_ = mismatch(q_path_.begin(), q_path_.end(), p_path_.begin());
				return vector<bool>(q_path_.begin(), qp_end_.first);
			} else {
				auto pq_end_ = mismatch(p_path_.begin(), p_path_.end(), q_path_.begin());
				return vector<bool>(p_path_.begin(), pq_end_.first);
			}
		}
	};
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		LCAFinder f(p,q);
		TreeTraverse(root, &f);
		auto path = f.GetLcaPath();
		for (bool direction: path) {
			root = direction? root->right: root->left;
		}
		return root;
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	TreeNode tns[10];
	tns[0].val =   37; tns[0].left = tns + 1; tns[0].right = tns + 2;
	tns[1].val =  -34; tns[1].left = nullptr; tns[1].right = tns + 3;
	tns[2].val =  -48; tns[2].left = tns + 4; tns[2].right = tns + 5;
	tns[3].val = -100; tns[3].left = nullptr; tns[3].right = nullptr;
	tns[4].val = -100; tns[4].left = nullptr; tns[4].right = nullptr;
	tns[5].val =   48; tns[5].left = tns + 6; tns[5].right = nullptr;
	tns[6].val =  -54; tns[6].left = tns + 7; tns[6].right = tns + 8;
	tns[7].val =  -71; tns[7].left = nullptr; tns[7].right = nullptr;
	tns[8].val =  -22; tns[8].left = nullptr; tns[8].right = tns + 9;
	tns[9].val =    8; tns[9].left = nullptr; tns[9].right = nullptr;
	printf("%d\n", s.lowestCommonAncestor(tns, tns+7, tns+9)->val);
	return 0;
}
