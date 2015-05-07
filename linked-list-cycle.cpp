#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode pseudo_head(0); pseudo_head.next = head;
		ListNode *fast = &pseudo_head;
		ListNode *slow = &pseudo_head;
		while (true) {
			for (int i = 0; i < 2; ++i) {
				fast = fast->next;
				if (fast == nullptr) {
					return false;
				}
			}
			slow = slow->next;
			if (fast == slow) {
				return true;
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
	printf("%d\n", (int)s.hasCycle(n));
	n[0].next = n+1;
	n[1].next = n;
	printf("%d\n", (int)s.hasCycle(n));
	return 0;
}
