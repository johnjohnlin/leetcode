#include <cstdio>

class Solution {
	int last_record;
	int length_from_last_space;
	void MeetSpace()
	{
		if (length_from_last_space != 0) {
			last_record = length_from_last_space;
		}
		length_from_last_space = 0;
	}
public:
	int lengthOfLastWord(const char *s)
	{
		last_record = 0;
		length_from_last_space = 0;
		while (*s != '\0') {
			if (*s == ' ') {
				MeetSpace();
			} else {
				++length_from_last_space;
			}
			++s;
		}
		MeetSpace();
		return last_record;
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.lengthOfLastWord("yazawa niko"));
	printf("%d\n", s.lengthOfLastWord("hello world"));
	printf("%d\n", s.lengthOfLastWord("a "));
	printf("%d\n", s.lengthOfLastWord("a"));
	return 0;
}
