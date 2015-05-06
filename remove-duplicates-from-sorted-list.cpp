struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode *prev = head;
		ListNode *cur = head->next;
		while (cur != nullptr) {
			if (prev->val == cur->val) {
				prev->next = cur->next;
			} else {
				prev = prev->next;
			}
			cur = cur->next;
		}
		return head;
	}
};
int main(int argc, char const* argv[])
{
	// Because this it too simple, I wrote it on the webpage...
	return 0;
}
