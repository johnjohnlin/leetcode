#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	static int CountList(ListNode *head, ListNode **tail = NULL)
	{
		int num_node = 0;
		ListNode *prev_head = NULL;
		while (head != NULL) {
			prev_head = head;
			head = head->next;
			++num_node;
		}
		if (tail != NULL) {
			*tail = prev_head;
		}
		return num_node;
	}

	static int ReverseAndCountList(ListNode *head, ListNode **tail = NULL)
	{
		int num_node = 0;
		ListNode *prev_head = NULL;
		while (head != NULL) {
			ListNode *tmp_next = head->next;
			head->next = prev_head;
			prev_head = head;
			head = tmp_next;
			++num_node;
		}
		if (tail != NULL) {
			*tail = prev_head;
		}
		return num_node;
	}

public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *tailA, *tailB;
		int num_node_A = CountList(headA, &tailA);
		int num_node_B = ReverseAndCountList(headB, &tailB);

		ListNode *tail_start_from_A;
		int num_node_from_A = CountList(headA, &tail_start_from_A);

		ListNode *first_common_node;
		// note: the two if/else condition cannot be reversed
		if (tail_start_from_A == headB) {
			int num_from_tailB = (num_node_A + num_node_B - 1 - num_node_from_A) / 2;

			first_common_node = tailB;
			for (int i = 0; i < num_from_tailB; ++i) {
				first_common_node = first_common_node->next;
			}
		} else if (tail_start_from_A == tailA) {
			first_common_node = NULL;
		}

		ReverseAndCountList(tailB);
		return first_common_node;
	}
};

int main(int argc, char const* argv[])
{
	ListNode nodes[6] = {{0},{0},{0},{0},{0},{0}};
	// 0-1-2-
	//       3-4-
	// 5-----
	nodes[0].next = nodes + 1;
	nodes[1].next = nodes + 2;
	nodes[2].next = nodes + 3;
	nodes[3].next = nodes + 4;
	nodes[4].next = NULL;
	nodes[5].next = nodes + 3;
	Solution s;

	printf("%ld\n", s.getIntersectionNode(nodes+0, nodes+5)-nodes);
	printf("%ld\n", s.getIntersectionNode(nodes+3, nodes+4)-nodes);
	printf("%ld\n", s.getIntersectionNode(nodes+4, nodes+3)-nodes);

	// 0-1-2-3-
	// 4-5-
	nodes[3].next = NULL;
	nodes[4].next = nodes + 5;
	nodes[5].next = NULL;
	printf("%d\n", int(s.getIntersectionNode(nodes+0, nodes+4) == NULL));
	return 0;
}
