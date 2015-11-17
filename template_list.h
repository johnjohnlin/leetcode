#pragma once
#include <vector>
#include <cstdio>
using std::vector;

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

