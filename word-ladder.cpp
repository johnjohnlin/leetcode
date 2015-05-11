#include <cstdio>
#include <unordered_set>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Solution {
	bool IsConnected(const string &s1, const string &s2) {
		size_t diff_count = 0;
		for (size_t i = 0; i < s1.size(); ++i) {
			diff_count += s1[i] != s2[i];
			if (diff_count == 2) {
				return false;
			}
		}
		return true;
	}
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& w)
	{
		const size_t n = w.size();
		vector<string> wordDict(w.begin(), w.end());
		queue<array<size_t,2>> bfs_fifo; // index, distance
		list<size_t> left;
		vector<bool> is_goal(n);

		// Special case
		if (IsConnected(beginWord, endWord)) {
			return 2;
		}

		// Initialize
		for (size_t i = 0; i < n; ++i) {
			auto& word = wordDict[i];
			bool is_start = IsConnected(beginWord, word);
			is_goal[i] = IsConnected(endWord, word);
			if (is_start) {
				if (is_goal[i]) {
					return 3;
				} else {
					// printf("+%lu,%lu %s\n", i, 2, wordDict[i].c_str());
					bfs_fifo.push({i, 2});
				}
			} else {
				left.push_back(i);
			}
		}

		// BFS
		while (bfs_fifo.size() != 0) {
			auto cur_idx = bfs_fifo.front()[0];
			auto cur_distance = bfs_fifo.front()[1];
			bfs_fifo.pop();
			for (auto it = left.begin(); it != left.end();) {
				size_t i = *it;
				if (IsConnected(wordDict[cur_idx], wordDict[i])) {
					if (is_goal[i]) {
						return cur_distance+2;
					}
					// printf("+%lu,%lu %s\n", i, cur_distance+1, wordDict[i].c_str());
					bfs_fifo.push({i, cur_distance+1});
					it = left.erase(it);
				} else {
					++it;
				}
			}
		}
		return 0;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	unordered_set<string> ss{"hot","dot","dog","lot","log"};
	printf("%d\n", s.ladderLength("hit", "cog", ss));
	return 0;
}
