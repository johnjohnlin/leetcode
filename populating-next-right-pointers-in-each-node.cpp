#include <stack>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
using namespace std;

struct TreeLinkNode {
	TreeLinkNode *next;
    TreeLinkNode *left;
    TreeLinkNode *right;
};

class Solution {
	enum HasDoneDirection {NEW_NODE = 0, DONE_LEFT, DONE_RIGHT};
public:
	void connect(TreeLinkNode* root) {
		if (root == nullptr) {
			return;
		}
#if 0
		// The most general way
		// NG because the tree is perfect binary tree by the spec
		vector<TreeLinkNode*> prev_nodes;
		stack<pair<TreeLinkNode*, HasDoneDirection>> traverse_stack;
		traverse_stack.push({root, NEW_NODE});
		while (traverse_stack.size() != 0) {
			const int depth = traverse_stack.size() - 1;
			TreeLinkNode *cur = traverse_stack.top().first;
			HasDoneDirection &state = traverse_stack.top().second;
			// Traversal
			switch (state) {
				case NEW_NODE: {
					// Update previous left one
					if (depth == prev_nodes.size()) {
						prev_nodes.push_back(nullptr);
					}
					assert(depth < prev_nodes.size());
					TreeLinkNode* &prev_node = prev_nodes[depth];
					if (prev_node != nullptr) {
						prev_node->next = cur;
					}
					prev_node = cur;
					// traverse
					if (cur->left != nullptr) {
						traverse_stack.push({cur->left, NEW_NODE});
						state = DONE_LEFT;
						break;
					}
				}
				case DONE_LEFT:
					// traverse
					if (cur->right != nullptr) {
						traverse_stack.push({cur->right, NEW_NODE});
						state = DONE_RIGHT;
						break;
					}
				case DONE_RIGHT:
					// traverse
					traverse_stack.pop();
			}
		}
		for (auto prev_node: prev_nodes) {
			prev_node->next = nullptr;
		}
#else
		TreeLinkNode *cur_layer_head = root;
		TreeLinkNode *next_layer_head = root->left;
		root->next = nullptr;
		while(true) {
			if (next_layer_head == nullptr) {
				break;
			}
			TreeLinkNode *cur = cur_layer_head;
			while(true) {
				TreeLinkNode *next = cur->next;
				// link next layer
				cur->left->next = cur->right;
				if (next != nullptr) {
					cur->right->next = next->left;
					cur = next;
				} else {
					cur->right->next = nullptr;
					break;
				}
			}
			cur_layer_head = next_layer_head;
			next_layer_head = next_layer_head->left;
		}
#endif
	}
};

int main(int argc, char const* argv[])
{
	TreeLinkNode tns[7];
	tns[0].left = tns + 1; tns[0].right = tns + 2;
	tns[1].left = tns + 3; tns[1].right = tns + 4;
	tns[2].left = tns + 5; tns[2].right = tns + 6;
	tns[3].left = nullptr; tns[3].right = nullptr;
	tns[4].left = nullptr; tns[4].right = nullptr;
	tns[5].left = nullptr; tns[5].right = nullptr;
	tns[6].left = nullptr; tns[6].right = nullptr;
	Solution s;
	s.connect(tns);
	for (auto &n: tns) {
		if (n.next == nullptr) {
			printf("nullptr\n");
		} else {
			printf("%ld\n", n.next - tns);
		}
	}
	return 0;
}
