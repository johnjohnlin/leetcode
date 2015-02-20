#include <string>
#include <algorithm>
#include <cstdio>
using std::reverse;
using std::string;

class Solution {
public:
	string addBinary(string a, string b)
	{
		string *shorter;
		string *longer;
		if (a.size() > b.size()) {
			longer = &a;
			shorter = &b;
		} else {
			longer = &b;
			shorter = &a;
		}

		string result;
		int carry = 0;
		auto iterator_shorter = shorter->rbegin();
		auto iterator_longer = longer->rbegin();
		while (iterator_shorter != shorter->rend()) {
			int digit1 = *iterator_longer - '0';
			int digit2 = *iterator_shorter - '0';
			int sum = carry + digit1 + digit2;
			carry = sum >> 1;
			result.push_back('0' + (sum & 1));
			++iterator_shorter;
			++iterator_longer;
		}
		while (iterator_longer != longer->rend()) {
			int digit = *iterator_longer - '0';
			result.push_back('0' + (carry ^ digit));
			carry = digit & carry;
			++iterator_longer;
		}
		if (carry) {
			result.push_back('1');
		}

		reverse(result.begin(), result.end());
		return result;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%s\n", s.addBinary("1", "111").c_str());
	printf("%s\n", s.addBinary("1", "101").c_str());
	return 0;
}
