#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() {}
	ListNode(int x) : val(x), next(NULL) {}

	template <class IntType=int> IntType ToInt() const {
		const IntType base = 10;
		IntType val = 0;
		IntType offset = 1;
		const ListNode *head = this;
		while (head != NULL) {
			val += offset * head->val;
			offset *= base;
			head = head->next;
		}
		return val;
	}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *head1, ListNode *head2) {
		ListNode *head_result;
		ListNode **append_here = &head_result;
		int carry = 0;

		while (carry || head1 != NULL || head2 != NULL) {
			const int v1 = head1? head1->val: 0;
			const int v2 = head2? head2->val: 0;
			head1 = head1 != NULL? head1->next: NULL;
			head2 = head2 != NULL? head2->next: NULL;

			int sum = v1+v2+carry;
			carry = int(sum >= 10);
			sum -= carry * 10;

			ListNode *new_node = new ListNode(sum);

			*append_here = new_node;
			append_here = &(new_node->next);
		}

		*append_here = NULL;
		return head_result;
	}
};

int main(int argc, char const* argv[])
{
	ListNode nodes[6];
	nodes[0].val = 2;
	nodes[0].next = nodes+1;

	nodes[1].val = 4;
	nodes[1].next = nodes+2;

	nodes[2].val = 3;
	nodes[2].next = NULL;

	nodes[3].val = 5;
	nodes[3].next = nodes+4;

	nodes[4].val = 6;
	nodes[4].next = nodes+5;

	nodes[5].val = 4;
	nodes[5].next = NULL;

	Solution s;

	{
		const int n0 = nodes[0].ToInt();
		const int n1 = nodes[3].ToInt();
		printf("%d %d\n", n0, n1);
		const int nsum = s.addTwoNumbers(nodes+0, nodes+3)->ToInt();
		printf("%d\n", nsum);
	}

	// 0, 81
	nodes[0].next = NULL;
	nodes[4].next = NULL;
	nodes[0].val = 0;
	nodes[3].val = 1;
	nodes[4].val = 8;

	{
		const int n0 = nodes[0].ToInt();
		const int n1 = nodes[3].ToInt();
		printf("%d %d\n", n0, n1);
		const int nsum = s.addTwoNumbers(nodes+0, nodes+3)->ToInt();
		printf("%d\n", nsum);
	}

	// 5, 5
	nodes[0].next = NULL;
	nodes[3].next = NULL;
	nodes[0].val = nodes[3].val = 5;

	{
		const int n0 = nodes[0].ToInt();
		const int n1 = nodes[3].ToInt();
		printf("%d %d\n", n0, n1);
		const int nsum = s.addTwoNumbers(nodes+0, nodes+3)->ToInt();
		printf("%d\n", nsum);
	}

	return 0;
}
