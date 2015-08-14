#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;


class Trie {
	struct TrieNode {
		vector<pair<char,TrieNode*>> children;
		~TrieNode() {
			for (auto &child: children) {
				delete child.second;
			}
		}
	};
	TrieNode* root;
	vector<pair<char,TrieNode*>>::iterator FindChildren(vector<pair<char,TrieNode*>> &children, const char target) {
		return find_if(children.begin(), children.end(), [target](const pair<char, TrieNode*> &p) {
			return p.first == target;
		});
	}
public:
	Trie(): root(new TrieNode()) {}
	~Trie() { delete root; }
	void insert(string word) {
		TrieNode *head = root;
		int i = 0;
		for (; i < word.size(); ++i) {
			auto &children = head->children;
			auto it = FindChildren(children, word[i]);
			if (it == children.end()) {
				break;
			} else {
				head = it->second;
			}
		}
		for (; i < word.size(); ++i) {
			auto &children = head->children;
			head = new TrieNode();
			children.emplace_back(word[i], head);
		}
		auto &children = head->children;
		children.emplace_back('$', new TrieNode());
	}
	bool search(string word) {
		TrieNode *head = root;
		for (int i = 0; i < word.size(); ++i) {
			auto &children = head->children;
			auto it = FindChildren(children, word[i]);
			if (it == children.end()) {
				return false;
			} else {
				head = it->second;
			}
		}
		auto &children = head->children;
		return FindChildren(children, '$') != children.end();
	}
	bool startsWith(string prefix) {
		TrieNode *head = root;
		for (int i = 0; i < prefix.size(); ++i) {
			auto &children = head->children;
			auto it = FindChildren(children, prefix[i]);
			if (it == children.end()) {
				return false;
			} else {
				head = it->second;
			}
		}
		return true;
	}
};


int main(int argc, char const* argv[])
{
	Trie trie;
	trie.insert("somestring");
	trie.insert("somesing");
	trie.insert("somsring");
	printf("%d\n", int(trie.startsWith("hello"))); // 0
	printf("%d\n", int(trie.startsWith("som"))); // 1
	printf("%d\n", int(trie.startsWith("soe"))); // 0
	printf("%d\n", int(trie.search("world"))); // 0
	printf("%d\n", int(trie.search("som"))); // 0
	printf("%d\n", int(trie.search("somestring"))); // 1
	printf("%d\n", int(trie.search("somesing"))); // 1
	printf("%d\n", int(trie.search("somsring"))); // 1
	return 0;
}
