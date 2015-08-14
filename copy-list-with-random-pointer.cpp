#include <unordered_map>
#include <cstdio>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode copied_pseudo_head(0);
		RandomListNode *copied_tail = &copied_pseudo_head;
		unordered_map<RandomListNode*, RandomListNode*> old_to_new;
		// Deep copy except for the random pointer
		while (head != nullptr) {
			RandomListNode *new_node = new RandomListNode(head->label);
			new_node->random = head->random;
			old_to_new.insert(make_pair(head, new_node));
			head = head->next;
			copied_tail = copied_tail->next = new_node;
		}
		copied_tail->next = nullptr;
		// Map the random pointer
		RandomListNode *copied_head = copied_pseudo_head.next;
		while (copied_head != nullptr) {
			RandomListNode *&chr = copied_head->random;
			if (chr != nullptr) {
				chr = old_to_new[chr];
			}
			copied_head = copied_head->next;
		}
		return copied_pseudo_head.next;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	RandomListNode r[5] = {0, 100, 200, 300, 400};
	for (int i = 0; i < 4; ++i) {
		r[i].next = r+i+1;
		r[i].random = r+4-i;
	}
	r[4].next = nullptr;
	RandomListNode *c;
	for (RandomListNode *c = r; c != nullptr; c = c->next) {
		printf("%p, %d, %d\n", c, c->label, c->random == nullptr? -1: c->random->label);
	}
	for (RandomListNode *c = s.copyRandomList(r); c != nullptr; c = c->next) {
		printf("%p, %d, %d\n", c, c->label, c->random == nullptr? -1: c->random->label);
	}
	return 0;
}
