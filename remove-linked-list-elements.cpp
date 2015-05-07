struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode pseudo_head(0); pseudo_head.next = head;
		ListNode *prev = &pseudo_head;
		ListNode *cur = head;
		while (cur != nullptr) {
			if (cur->val == val) {
				prev->next = cur->next;
			} else {
				prev = prev->next;
			}
			cur = cur->next;
		}
		return pseudo_head.next;
	}
};
int main(int argc, char const* argv[])
{
	// Because this it too simple, I wrote it on the webpage...
	return 0;
}
