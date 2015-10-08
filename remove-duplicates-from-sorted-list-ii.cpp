#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

pair<ListNode*, vector<ListNode>> CreateList(const vector<int> &v) {
	const int n = v.size();
	pair<ListNode*,vector<ListNode>> ret{nullptr, vector<ListNode>(n, ListNode(0))};
	if (n == 0) {
		return ret;
	}
	ret.first = ret.second.data();
	auto &data = ret.second;
	for (int i = 0; i < n; ++i) {
		data[i].val = v[i];
		data[i].next = data.data()+i+1;
	}
	data.back().next = nullptr;
	return ret;
}

void PrintList(ListNode *head) {
	while (head != nullptr) {
		printf("%d->", head->val);
		head = head->next;
	}
	puts("$");
}

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode fake_head(0);
		ListNode *tail = &fake_head;
		int count = 1;
		tail->next = head;
		head = head->next;
		while (head != nullptr) {
			if (tail->next->val == head->val) {
				++count;
			} else {
				if (count == 1) {
					// accept the last node
					tail = tail->next;
				} else {
					// skip the last node
					tail->next = head;
				}
				count = 1;
			}
			head = head->next;
		}
		if (count == 1) {
			// accept the last node
			tail->next->next = nullptr;
		} else {
			// skip the last node
			tail->next = nullptr;
		}
		return fake_head.next;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto q1 = CreateList({1,1,1,1,1,2,3,3,4,4,5,6,7,7,8});
	auto q2 = CreateList({1,1,1,1,1,2,3,3,4,4,5,6,7,7,8,8});
	auto q3 = CreateList({1,1});
	PrintList(s.deleteDuplicates(q1.first));
	PrintList(s.deleteDuplicates(q2.first));
	PrintList(s.deleteDuplicates(q3.first));
	return 0;
}
