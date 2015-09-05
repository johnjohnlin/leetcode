#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	string makeLine(
		const vector<string>& words,
		const int group_start, const int group_size, const int total_space, const int maxWidth
	) {
		assert(group_size != 0);
		string ret(maxWidth, ' ');
		auto fill_pos = ret.begin();
		fill_pos = copy(words[group_start].begin(), words[group_start].end(), fill_pos);
		if (group_size > 1) {
			const int n_delim = group_size-1;
			const int n_space = total_space / n_delim;
			const int residue = total_space % n_delim;
			for (int i = 0; i < n_delim; ++i) {
				fill_pos += n_space + int(i < residue);
				fill_pos = copy(words[group_start+1+i].begin(), words[group_start+1+i].end(), fill_pos);
			}
		}
		return ret;
	}
	string makeLastLine(
		const vector<string>& words,
		const int group_start, const int group_size, const int maxWidth
	) {
		assert(group_size != 0);
		string ret(maxWidth, ' ');
		auto fill_pos = ret.begin();
		fill_pos = copy(words[group_start].begin(), words[group_start].end(), fill_pos);
		for (int i = 1; i < group_size; ++i) {
			++fill_pos;
			fill_pos = copy(words[group_start+i].begin(), words[group_start+i].end(), fill_pos);
		}
		return ret;
	}
public:
	vector<string> fullJustify(const vector<string>& words, const int maxWidth) {
		vector<string> ret;
		int group_start = 0, group_size = 0, space_left = maxWidth, line_left = maxWidth;
		for (int i = 0; i < words.size(); ++i) {
			const int extra_space = group_size != 0;
			const int line_consume = extra_space+words[i].size();
			if (line_left >= line_consume) {
				space_left -= words[i].size();
				line_left -= line_consume;
				++group_size;
			} else {
				ret.push_back(makeLine(words, group_start, group_size, space_left, maxWidth));
				group_start = i, group_size = 0, space_left = maxWidth, line_left = maxWidth;
				--i; // do this string again (will enter the if block)
			}
		}
		ret.push_back(makeLastLine(words, group_start, group_size, maxWidth));
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	auto ans1 = s.fullJustify(
		{"This", "is", "an", "example", "of", "text", "justification."},
		16
	);
	for (auto &&s: ans1) {
		puts(s.c_str());
	}
	auto ans2 = s.fullJustify(
		{""},
		0
	);
	for (auto &&s: ans2) {
		puts(s.c_str());
	}
	auto ans3 = s.fullJustify(
		{"What","must","be","shall","be."},
		12
	);
	for (auto &&s: ans3) {
		puts(s.c_str());
	}
	return 0;
}
