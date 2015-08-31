#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	string thousandToWords(int num) {
		const char *english_10_90[] = {
			" Ten",
			" Twenty",
			" Thirty",
			" Forty",
			" Fifty",
			" Sixty",
			" Seventy",
			" Eighty",
			" Ninty"
		};
		const char *english_1_19[] = {
			" One",
			" Two",
			" Three",
			" Four",
			" Five",
			" Six",
			" Seven",
			" Eight",
			" Nine",
			" Ten",
			" Eleven",
			" Twelve",
			" Thirteen",
			" Forteen",
			" Fifteen",
			" Sixteen",
			" Seventeen",
			" Eighteen",
			" Ninteen"
		};
		string ret;
		const int hund_dig = num/100;
		if (hund_dig != 0) {
			ret += english_1_19[hund_dig-1];
			ret += " Hundred";
		}
		num %= 100;
		if (0 < num and num <= 19) {
			ret += english_1_19[num-1];
		} else {
			const int ten_dig = num / 10;
			const int one_dig = num % 10;
			if (ten_dig != 0) {
				ret += english_10_90[ten_dig-1];
			}
			if (one_dig != 0) {
				ret += english_1_19[one_dig-1];
			}
		}
		return ret;
	}
public:
	string numberToWords(int num) {
		if (num == 0) {
			return "Zero";
		}
		const pair<int, const char*> units[4] = {
			{1000000000,  " Billion"},
			{   1000000,  " Million"},
			{      1000, " Thousand"},
			{         1,          ""}
		};
		string ret;
		for (const auto &unit: units) {
			const int digit = num / unit.first;
			if (digit != 0) {
				ret += thousandToWords(digit);
				ret += unit.second;
			}
			num -= digit * unit.first;
		}
		return ret.substr(1);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	puts(s.numberToWords(0).c_str());
	puts(s.numberToWords(119).c_str());
	puts(s.numberToWords(123).c_str());
	puts(s.numberToWords(123456).c_str());
	puts(s.numberToWords(100013).c_str());
	puts(s.numberToWords(100413).c_str());
	puts(s.numberToWords(123456789).c_str());
	return 0;
}
