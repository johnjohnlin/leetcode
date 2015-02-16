#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		int i = 0;
		if (strs.size() == 0) {
			return string();
		} else if (strs.size() == 1) {
			return strs[0];
		}

		size_t common_len = 0;
		while (true) {
			char reference = strs[0][common_len];
			for (int i = 1; i < strs.size(); ++i) {
				if (common_len == strs[i].size() || strs[i][common_len] != reference) {
					return strs[0].substr(0, common_len);
				}
			}
			++common_len;
		}

	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<string> t1{"hello", "helloworld", "hello "};
	vector<string> t2{"absolute", "abhh", "ab"};
	printf("%s\n", s.longestCommonPrefix(t1).c_str());
	printf("%s\n", s.longestCommonPrefix(t2).c_str());
	return 0;
}
