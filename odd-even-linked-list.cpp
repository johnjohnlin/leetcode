#include "template_list.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <queue>
#include <cstdio>
using namespace std;

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode phead[2] = {0, 0};
		ListNode *tail[2] = {phead+0, phead+1};
		int i = 0;
		while (head != nullptr) {
			ListNode *&append = tail[i%2];
			append = append->next = head;
			head = head->next;
			++i;
		}
		tail[0]->next = phead[1].next;
		tail[1]->next = nullptr;
		return phead[0].next;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto l1 = CreateList({1,2,3});
	auto l2 = CreateList({1,2});
	auto l3 = CreateList({1});
	auto l4 = CreateList({});
	PrintList(s.oddEvenList(l1.first));
	PrintList(s.oddEvenList(l2.first));
	PrintList(s.oddEvenList(l3.first));
	PrintList(s.oddEvenList(l4.first));
	return 0;
}
