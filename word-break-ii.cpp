#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>

using namespace std;
class Solution {
	const size_t HEAD_ = string::npos;
	const vector<vector<size_t>> buildGraph(const string &s, const unordered_set<string>& wordDict) {
		vector<vector<size_t>> possible_prev(s.size());
		const size_t len_s = s.size();
		for (const string &word: wordDict) {
			const size_t len_w = word.size();
			if (len_w <= len_s and equal(word.begin(), word.end(), s.begin())) {
				possible_prev[len_w-1].push_back(HEAD_);
			}
		}
		for (size_t i = 0; i < len_s-1; ++i) {
			// printf("%zu\n", i);
			if (possible_prev[i].size()) {
				for (const string &word: wordDict) {
					const size_t len_w = word.size();
					// consider i = -1, it becomes the initialization
					// puts(word.c_str());
					// if (i+len_w < len_s) {
					// 	puts(s.substr(i+1, len_w).c_str());
					// }
					if (i+len_w < len_s and equal(word.begin(), word.end(), s.begin()+i+1)) {
						possible_prev[i+len_w].push_back(i);
					}
				}
			}
			// printf("%zu\n", i);
		}
		return possible_prev;
	}
	void trimGraph(vector<vector<size_t>> &possible_prev) {
		vector<bool> visited(possible_prev.size(), false);
		visited.back() = true;
		queue<size_t> bfs_queue;
		bfs_queue.push(possible_prev.size()-1);
		while (bfs_queue.size() != 0) {
			const size_t cur = bfs_queue.front(); bfs_queue.pop();
			// printf("-%zu\n", cur);
			const auto &prevs = possible_prev[cur];
			for (const size_t prev: prevs) {
				if (prev != HEAD_ and not visited[prev]) {
					// printf("+%zu\n", prev);
					bfs_queue.push(prev);
					visited[prev] = true;
				}
			}
		}
		for (size_t i = 0; i < possible_prev.size(); ++i) {
			if (not visited[i]) {
				possible_prev[i].resize(0);
			}
		}
	}
	const vector<string> dpBuild(const string &s, const vector<vector<size_t>> &possible_prev) {
		const size_t len_s = s.size();
		vector<vector<string>> dp_table(len_s);
		for (size_t i = 0; i < len_s; ++i) {
			const auto &prevs = possible_prev[i];
			for (const size_t prev: prevs) {
				if (prev == HEAD_) {
					dp_table[i].push_back(s.substr(0, i+1));
				} else {
					for (const string &prev_ans: dp_table[prev]) {
						// consider prev = -1, it becomes the previous case
						dp_table[i].push_back(prev_ans + " " + s.substr(prev+1, i-prev));
					}
				}
			}
		}
		return dp_table.back();
	}

public:
	const vector<string> wordBreak(const string &s, const unordered_set<string>& wordDict) {
		if (s.size() == 0) {
			// empty string
			return vector<string>();
		}
		vector<vector<size_t>> possible_prev = buildGraph(s, wordDict);
		assert(s.size() == possible_prev.size());
		if (possible_prev.back().size() == 0) {
			// cannot reach the end
			return vector<string>();
		}
		trimGraph(possible_prev);
		return dpBuild(s, possible_prev);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (const auto &st: s.wordBreak("catsanddog", {"cat", "cats", "and", "sand", "dog"})) {
		puts(st.c_str());
	}
	puts("==");
	for (const auto &st: s.wordBreak("leetcode", {"leet", "code"})) {
		puts(st.c_str());
	}
	puts("==");
	for (const auto &st: s.wordBreak("leetcode", {"l", "tcode", "e"})) {
		puts(st.c_str());
	}
	puts("==");
	for (const auto &st: s.wordBreak("leetcode", {"l", "code", "e"})) {
		puts(st.c_str());
	}
	puts("==");
	return 0;
}
