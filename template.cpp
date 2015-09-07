#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

pair<ListNode*, vector<ListNode>> CreateList(const vector<int> &v) {
	const int n = v.size();
	pair<ListNode*,vector<ListNode>> ret{nullptr, vector<ListNode>(n, {0})};
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

inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	putchar('\n');
}

inline void PrintMatrix(const vector<vector<int>> &m) {
	for (auto &v: m) {
		PrintVector(v);
	}
	puts("====");
}

int main(int argc, char const* argv[])
{
	Solution s;
	return 0;
}
