#include <string>
#include <cassert>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<pair<int,int>> substr_stack;
		size_t prev_slash = 0;
		while (prev_slash != path.size()) {
			size_t next_slash = path.find('/', prev_slash+1);
			if (next_slash == string::npos) {
				next_slash = path.size();
			}
			size_t len = next_slash-prev_slash;
			assert(len != 0);
			switch (len) {
				case 1:
					break;
				case 2:
					if (path[prev_slash+1] == '.') {
						break;
					}
				case 3:
					if (path[prev_slash+1] == '.' and path[prev_slash+2] == '.') {
						if (substr_stack.size() != 0) {
							substr_stack.pop_back();
						}
						break;
					}
				default:
					substr_stack.emplace_back(prev_slash, len);
			}
			prev_slash = next_slash;
		}
		string ret;
		for (auto &p: substr_stack) {
			ret += path.substr(p.first, p.second);
		}
		if (ret.size() == 0) {
			ret.push_back('/');
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%s\n", s.simplifyPath("/home//foo/bar/hello").c_str());
	printf("%s\n", s.simplifyPath("/../../a/b/../c/./c/").c_str());
	return 0;
}
