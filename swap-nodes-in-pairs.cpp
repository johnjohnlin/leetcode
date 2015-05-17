#include <cstdio>
#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x=0) : val(x), next(nullptr) {}
};

void PrintList(ListNode *head){
	while (head != nullptr) {
		printf("%d -> ", head->val);
		head = head->next;
	}
	puts("nullptr");
}

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode pseudo_head(0); pseudo_head.next = head;
		ListNode *tail = &pseudo_head;
		ListNode *cur = head;
		while (cur != nullptr) {
			// Advance
			ListNode *n1 = cur;
			cur = cur->next;
			if (cur == nullptr) {
				break;
			}
			ListNode *n2 = cur;
			cur = cur->next;
			// Swap
			tail->next = n2;
			n1->next = n2->next;
			n2->next = n1;
			tail = n1;
		}

		return pseudo_head.next;
	}
};

int main(int argc, char const* argv[])
{
	ListNode n[4];
	n[0].val = 1; n[0].next = n+1;
	n[1].val = 2; n[1].next = n+2;
	n[2].val = 3; n[2].next = nullptr;
	PrintList(n);
	Solution s;
	auto new_head = s.swapPairs(n);
	PrintList(new_head);
	return 0;
}
