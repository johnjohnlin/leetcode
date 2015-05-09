#include <cstdio>
#include <string>
using namespace std;

class Solution {
	size_t prev_idx[2];
	bool is_end[2];
	string *version[2];

	unsigned long GetNextSubVersionNumuer(const int i) {
		if (is_end[i]) {
			return 0ul;
		} else {
			size_t next_idx = version[i]->find('.', prev_idx[i]);
			is_end[i] = next_idx == string::npos;
			if (is_end[i]) {
				return stoul(version[i]->substr(prev_idx[i]));
			} else {
				auto sub_ver_num = stoul(version[i]->substr(prev_idx[i], next_idx-prev_idx[i]));
				prev_idx[i] = next_idx+1;
				return sub_ver_num;
			}
		}
	}
public:
	int compareVersion(string version1, string version2) {
		prev_idx[0] = prev_idx[1] = 0;
		is_end[0] = is_end[1] = false;
		version[0] = &version1;
		version[1] = &version2;
		while (true) {
			const unsigned long v1 = GetNextSubVersionNumuer(0);
			const unsigned long v2 = GetNextSubVersionNumuer(1);
			// printf("%lu vs %lu\n", v1, v2);
			if (v1 > v2) {
				return 1;
			} else if (v1 < v2) {
				return -1;
			}
			if (is_end[0] && is_end[1]) {
				return 0;
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.compareVersion("0.1", "1.1"));
	printf("%d\n", s.compareVersion("1.1", "1.2"));
	printf("%d\n", s.compareVersion("0.1", "13.37"));
	printf("%d\n", s.compareVersion("0", "1.37"));
	printf("%d\n", s.compareVersion("1", "1.37"));
	printf("%d\n", s.compareVersion("2", "1.37"));
	printf("%d\n", s.compareVersion("1", "1"));
	printf("%d\n", s.compareVersion("1", "1.0")); // WTF, it's the same...
	printf("%d\n", s.compareVersion("3.14159", "3.14159"));
	return 0;
}
