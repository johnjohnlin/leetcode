#include <string>
#include <list>
#include <cstdio>
using std::string;
using std::list;

class Solution {
	struct string_ref {
		// inclusive
		size_t start, end;
	};

	list<string_ref> candidate_;
	string s_;

	string StartFromCandidate()
	{
		string_ref last_valid{0, 0};

		while (candidate_.size() != 0) {
			auto it = candidate_.begin();
			const size_t max_end = s_.size()-1;
			last_valid = candidate_.front();

			while (it != candidate_.end()) {
				const bool not_edge = it->start != 0 && it->end != max_end;
				if (not_edge && s_[it->start-1] == s_[it->end+1]) {
					--(it->start);
					++(it->end);
					++it;
				} else {
					it = candidate_.erase(it);
				}
			}
		}

		return s_.substr(last_valid.start, last_valid.end-last_valid.start+1);
	}

public:

	string longestPalindrome(string s)
	{
		s_ = s;
		if (s.size() <= 2) {
			// 2 is ok because "ab" has 2 ans
			return s;
		}

		candidate_.clear();
		for (size_t i = 0; i < s_.size(); i++) {
			candidate_.push_back(string_ref{i, i});
		}
		string odd_string = StartFromCandidate();

		candidate_.clear();
		for (size_t i = 0; i < s_.size()-1; i++) {
			if (s_[i] == s_[i+1]) {
				candidate_.push_back(string_ref{i, i+1});
			}
		}
		string even_string = StartFromCandidate();


		return even_string.size() > odd_string.size()? even_string: odd_string;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%s\n", s.longestPalindrome("a1234321bbb").c_str());
	printf("%s\n", s.longestPalindrome("a").c_str());
	printf("%s\n", s.longestPalindrome("bb").c_str());
	printf("%s\n", s.longestPalindrome("aba").c_str());
	return 0;
}
