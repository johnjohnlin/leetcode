#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
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
	ListNode* partition(ListNode* head, int x) {
		ListNode ge_head(0); ge_head.next = nullptr;
		ListNode lt_head(0); lt_head.next = nullptr;
		ListNode *ge_cur = &ge_head;
		ListNode *lt_cur = &lt_head;
		while (head != nullptr) {
			if (head->val >= x) {
				ge_cur = ge_cur->next = head;
			} else {
				lt_cur = lt_cur->next = head;
			}
			head = head->next;
		}
		lt_cur->next = ge_head.next;
		ge_cur->next = nullptr;
		return lt_head.next;
	}
};



int main(int argc, char const* argv[])
{
	ListNode n[3];
	n[0].val = 100; n[0].next = n+1;
	n[1].val = 3; n[1].next = n+2;
	n[2].val = 2; n[2].next = nullptr;
	PrintList(n);
	Solution s;
	auto rev_head = s.partition(n, 93);
	PrintList(rev_head);
	return 0;
}
