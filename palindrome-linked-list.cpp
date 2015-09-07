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
	ListNode(int x) : val(x), next(NULL) {}
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
	bool isPalindrome(ListNode* head) {
		ListNode *cur;
		// Counting
		int n = 0;
		cur = head;
		while (cur) {
			cur = cur->next;
			++n;
		}
		// reverse the first part
		ListNode *ahead = head;
		cur = nullptr;
		for (int i = 0; i < n/2; ++i) {
			ListNode *tmp_next = ahead->next;
			ahead->next = cur;
			cur = ahead;
			ahead = tmp_next;
		}
		if (n % 2 == 1) {
			ahead = ahead->next;
		}
		// We must check n/2 nodes
		ListNode *a = ahead, *b = cur;
		for (int i = 0; i < n/2; ++i) {
			if (a->val != b->val) {
				return false;
			}
			a = a->next;
			b = b->next;
		}
		return true;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto q1 = CreateList({1,2,3,4,5,6});
	auto q2 = CreateList({1,2,3,3,2,1});
	auto q3 = CreateList({1,2,3,4,5});
	auto q4 = CreateList({1,2,3,2,1});
	auto q5 = CreateList({1,2,2,1});
	auto q6 = CreateList({1,2,1});
	auto q7 = CreateList({1,2,3,4});
	auto q8 = CreateList({1,2,3});
	auto q9 = CreateList({1});
	auto q10 = CreateList({});
	// 0 1 0 1 1 1 0 0 1 1
	printf("%d\n", s.isPalindrome(q1.first));
	printf("%d\n", s.isPalindrome(q2.first));
	printf("%d\n", s.isPalindrome(q3.first));
	printf("%d\n", s.isPalindrome(q4.first));
	printf("%d\n", s.isPalindrome(q5.first));
	printf("%d\n", s.isPalindrome(q6.first));
	printf("%d\n", s.isPalindrome(q7.first));
	printf("%d\n", s.isPalindrome(q8.first));
	printf("%d\n", s.isPalindrome(q9.first));
	printf("%d\n", s.isPalindrome(q10.first));
	return 0;
}
