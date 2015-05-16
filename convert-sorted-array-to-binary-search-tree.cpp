#include <stack>
#include <cstdio>
#include <memory>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		const int n = nums.size();
		if (n == 0) {
			return nullptr;
		}

		unique_ptr<TreeNode*[]> ret(new TreeNode*[n]);
		for (int i = 0; i < n; ++i) {
			ret[i] = new TreeNode(nums[i]);
		}
		struct StackInfo {
			int base;
			int n;
			HasDoneDirection state;
		};

		stack<StackInfo> traverse_stack;
		traverse_stack.push({0, n, NEW_NODE});
		while (traverse_stack.size() != 0) {
			int base = traverse_stack.top().base;
			const int n = traverse_stack.top().n;
			HasDoneDirection &state = traverse_stack.top().state;
			const int n_left = n/2;
			const int n_right = (n-1)/2;
			const int mid_idx = n/2;
			// Traversal
			switch (state) {
				case NEW_NODE:
					if (n_left > 0) {
						traverse_stack.push({base, n_left, NEW_NODE});
						ret[base+mid_idx]->left = ret[base+n_left/2];
					} else {
						ret[base+mid_idx]->left = nullptr;
					}
					state = DONE_LEFT;
					break;
				case DONE_LEFT:
					if (n_right > 0) {
						traverse_stack.push({base+mid_idx+1, n_right, NEW_NODE});
						ret[base+mid_idx]->right = ret[base+mid_idx+1+n_right/2];
					} else {
						ret[base+mid_idx]->right = nullptr;
					}
					state = DONE_RIGHT;
					break;
				case DONE_RIGHT:
					traverse_stack.pop();
			}
		}
		return ret[n/2];
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	{
		vector<int> v{1, 3};
		auto root = s.sortedArrayToBST(v);
		printf("%p %d\n", root, root->val);
		printf("%p %d\n", root->left, root->left->val);
		printf("%p\n", root->right);
	}
	return 0;
}
