#include <string>
#include <vector>
#include <algorithm>
using std::transform;
using std::vector;
using std::string;
using std::distance;

class Solution {
	static const char *key_chars[];
public:
	vector<string> letterCombinations(string digits) {

		vector<string> all_combinations;
		vector<const char*> pointer_stack(digits.size());
		// initialize: convert digits to pointers
		transform(
			digits.begin(), digits.end(),
			pointer_stack.begin(),
			[](char c) -> const char* {return key_chars[c-'2'];}
		);

		while (true) {
			string current_combination(digits.size(), '\0');
			// build the string
			transform(
				pointer_stack.begin(), pointer_stack.end(),
				current_combination.begin(),
				[](const char *p) -> char {return *p;}
			);
			all_combinations.push_back(current_combination);

			auto it = pointer_stack.rbegin();
			while(it != pointer_stack.rend()) {
				const char* &cstr_ptr = *it;
				++cstr_ptr;
				if (*cstr_ptr != '\0') {
					// reset pointers after `it`
					transform(
						digits.rbegin(), digits.rbegin() + distance(pointer_stack.rbegin(), it),
						pointer_stack.rbegin(),
						[](char c) -> const char* {return key_chars[c-'2'];}
					);
					break;
				} else {
					++it;
				}
			}
			if (it == pointer_stack.rend()) {
				break;
			}
		}

		return all_combinations;
	}
};

const char* Solution::key_chars[] = {
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (string &str: s.letterCombinations("23")) {
		printf("%s\n", str.c_str());
	}
	puts("===");
	for (string &str: s.letterCombinations("234")) {
		printf("%s\n", str.c_str());
	}
	return 0;
}
