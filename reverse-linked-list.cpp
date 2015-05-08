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
	ListNode* reverseList(ListNode* head) {
		ListNode *rev_head = nullptr;
		while (head != nullptr) {
			ListNode *next_tmp = head->next;
			head->next = rev_head;
			rev_head = head;
			head = next_tmp;
		}
		return rev_head;
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
	auto rev_head = s.reverseList(n);
	PrintList(rev_head);
	return 0;
}
