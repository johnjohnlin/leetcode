#include "template_matrix.h"
#include "template_tree.h"
#include "template_list.h"
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <functional>
#include <vector>
#include <stack>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	int S2I(const string &s) {
		return s[0]*65536 + s[1]*256 + s[2];
	}
	string I2S(int i) {
		char s[4] = {i/65536, (i/256)%256, i%256, '\0'};
		return string(s);
	}
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<int, vector<int>> graph;
		for (auto ticket: tickets) {
			int src = S2I(ticket.first);
			int dst = S2I(ticket.second);
			graph.insert(make_pair(src, vector<int>())).first->second.push_back(dst);
		}
		for (auto &outs: graph) {
			sort(outs.second.begin(), outs.second.end(), greater<int>());
		}
		const int JFK = S2I("JFK");
		vector<int> reti;
		stack<int> sti; sti.push(JFK);
		while (not sti.empty()) {
			auto &outs = graph[sti.top()];
			if (outs.empty()) {
				reti.push_back(sti.top());
				sti.pop();
			} else {
				sti.push(outs.back());
				outs.pop_back();
			}
		}
		vector<string> ret; ret.reserve(reti.size());
		while (not reti.empty()) {
			ret.push_back(I2S(reti.back()));
			reti.pop_back();
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto ans1 = s.findItinerary({{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}});
	for (auto &s: ans1) {
		puts(s.c_str());
	}
	puts("==");
	auto ans2 = s.findItinerary({{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}});
	for (auto &s: ans2) {
		puts(s.c_str());
	}
	return 0;
}
