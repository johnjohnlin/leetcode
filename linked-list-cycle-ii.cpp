#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode* head) {
		ListNode pseudo_head(0); pseudo_head.next = head;
		ListNode *fast = &pseudo_head;
		ListNode *slow = &pseudo_head;
		while (true) {
			for (int i = 0; i < 2; ++i) {
				fast = fast->next;
				if (fast == nullptr) {
					return nullptr;
				}
			}
			slow = slow->next;
			if (fast == slow) {
				// magic!
				ListNode *p1 = &pseudo_head;
				ListNode *p2 = fast;
				while (p1 != p2) {
					p1 = p1->next;
					p2 = p2->next;
				}
				return p1;
			}
		}
	}
};
int main(int argc, char const* argv[])
{
	ListNode n[3];
	Solution s;
	n[0].next = n+1;
	n[1].next = n+2;
	n[2].next = nullptr;
	printf("%ld\n", s.detectCycle(n) - n);
	n[0].next = n+1;
	n[1].next = n;
	printf("%ld\n", s.detectCycle(n) - n);
	return 0;
}
