#include <string>
#include <cstdio>
#include <cctype>
using std::string;

class Solution {
	string *s_;
	string::iterator first_;
	string::iterator last_;

	void DecrementLast()
	{
		while (last_ != s_->begin()) {
			--last_;
			if (isalnum(*last_)) {
				break;
			}
		}
	}

	void IncrementFirst()
	{
		while (first_ != s_->end()) {
			++first_;
			if (isalnum(*first_)) {
				break;
			}
		}
	}

public:
	bool isPalindrome(string s)
	{
		if (s.size() <= 1) {
			return true;
		}

		s_ = &s;
		first_ = s_->begin();
		last_ = s_->end();
		if (!isalnum(*first_)) {
			IncrementFirst();
		}
		DecrementLast();

		while (first_ < last_) {
			if (tolower(*first_) != tolower(*last_)) {
				return false;
			}
			DecrementLast();
			IncrementFirst();
		}

		return true;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.isPalindrome("A man, a plan, a canal: Panama"));
	printf("%d\n", s.isPalindrome(" r"));
	printf("%d\n", s.isPalindrome("r "));
	printf("%d\n", s.isPalindrome("r"));
	printf("%d\n", s.isPalindrome(";;'/;"));
	printf("%d\n", s.isPalindrome(";"));
	printf("%d\n", s.isPalindrome(""));

	puts("===");

	printf("%d\n", s.isPalindrome("1a2"));
	printf("%d\n", s.isPalindrome("race a car"));
	printf("%d\n", s.isPalindrome(" ra"));
	printf("%d\n", s.isPalindrome("ra "));
	printf("%d\n", s.isPalindrome("r a"));
	return 0;
}
