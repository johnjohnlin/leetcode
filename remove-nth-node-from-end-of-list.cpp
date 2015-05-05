#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// n is always valid

		// Using pseudo head, we don't need to handle removing the first element
		ListNode pseudo_head(0);
		pseudo_head.next = head;

		// Let back n+1 left behind
		ListNode *front = head;
		ListNode *back = &pseudo_head;
		for (int i = 0; i < n; ++i) {
			front = front->next;
		}

		// Advance both front and back
		while (front != nullptr) {
			front = front->next;
			back = back->next;
		}

		// Remove
		back->next = back->next->next;
		return pseudo_head.next;
	};
};

int main(int argc, char const* argv[])
{
	// I don't want to test...
	return 0;
}
