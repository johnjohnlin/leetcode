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

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) {
			return nullptr;
		}
		int n = 1;
		ListNode *cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
			++n;
		}
		k %= n;
		if (k == 0) {
			return head;
		}
		ListNode *tail = cur;
		cur = head;
		for (int i = 1; i < n-k; ++i) {
			cur = cur->next;
		}
		ListNode *new_head = cur->next;
		tail->next = head;
		cur->next = nullptr;
		return new_head;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	return 0;
}
