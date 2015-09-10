#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <queue>
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		struct PqData{
			int which, value;
		};
		auto comp = [](const PqData& l, const PqData &r) { return l.value >= r.value; };
		priority_queue<PqData, vector<PqData>, decltype(comp)> pq(comp);
		ListNode fake_head(0);
		ListNode *head = &fake_head;
		for (int which = 0; which < lists.size(); ++which) {
			ListNode* &new_node = lists[which];
			if (new_node != nullptr) {
				pq.push({which, new_node->val});
			}
		}
		while (pq.size() != 0) {
			PqData smallest_entry = pq.top();
			pq.pop();
			const int which = smallest_entry.which;
			ListNode* &new_node = lists[which];
			head->next = new_node;
			head = new_node;
			new_node = new_node->next;
			if (new_node != nullptr) {
				pq.push({which, new_node->val});
			}
		}
		head->next = nullptr;
		return fake_head.next;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto l1 = CreateList({1,3,4,5,6,7,8});
	auto l2 = CreateList({-1,2,3,9});
	auto l3 = CreateList({-1,-1});
	auto l4 = CreateList({});
	vector<ListNode*> ls = {l1.first, l2.first, l3.first, l4.first};
	ListNode *ans = s.mergeKLists(ls);
	PrintList(ans);
	return 0;
}
