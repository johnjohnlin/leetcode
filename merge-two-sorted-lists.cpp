#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode *l2) {
		ListNode merged(0); merged.next = nullptr;
		ListNode *merged_tail = &merged;
		while (true) {
			if (l1 == nullptr) {
				merged_tail->next = l2;
				break;
			} else if (l2 == nullptr) {
				merged_tail->next = l1;
				break;
			} else {
				if (l1->val < l2->val) {
					merged_tail->next = l1;
					merged_tail = l1;
					l1 = l1->next;
				} else {
					merged_tail->next = l2;
					merged_tail = l2;
					l2 = l2->next;
				}
			}
		}
		return merged.next;
	}
};

int main(int argc, char const* argv[])
{
	ListNode n[3];
	n[0].val = 1; n[0].next = n+1;
	n[1].val = 2; n[1].next = n+2;
	n[2].val = 3; n[2].next = nullptr;
	PrintList(n);
	Solution s;
	auto merged = s.mergeTwoLists(n, nullptr);
	PrintList(merged);
	return 0;
}
