#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string rev;
		vector<string> words;
		// split the words
		enum State {PARSE_WORD, PARSE_SPACE} state = PARSE_SPACE;
		for (char c: s) {
			switch (state) {
				case PARSE_SPACE:
					if (c != ' ') {
						words.emplace_back(1, c);
						state = PARSE_WORD;
					}
					break;
				case PARSE_WORD:
					if (c == ' ') {
						state = PARSE_SPACE;
					} else {
						words.back().push_back(c);
					}
					break;
			}
		}
		// reverse
		if (words.size() == 0) {
			s.resize(0);
		} else {
			rev = words.back();
			for (auto word = words.rbegin()+1; word != words.rend(); ++word) {
				rev += ' ';
				rev += *word;
			}
			s = rev;
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	string st(" Hello world   hihi   ");
	s.reverseWords(st);
	printf("%s\n", st.c_str());
	return 0;
}
