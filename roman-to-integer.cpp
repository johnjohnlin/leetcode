#include <string>
using std::string;

class Solution {
	enum Digit {
		I_1 = 0,
		V_5,
		X_10,
		L_50,
		C_100,
		D_500,
		M_1000
	};

	static inline Digit CharToDigit(const char c)
	{
		switch (c) {
			case 'I':
				return I_1;
			case 'V':
				return V_5;
			case 'X':
				return X_10;
			case 'L':
				return L_50;
			case 'C':
				return C_100;
			case 'D':
				return D_500;
			case 'M':
			default:
				return M_1000;
		}
	}

	static inline int DigitToNumber(const Digit d)
	{
		static int table[] = {1,5,10,50,100,500,1000};
		return table[(int)d];
	}
public:
	int romanToInt(string s)
	{
		bool ambigious_negative = false;
		Digit ambigious_digit;
		int number = 0;

		for (char c: s) {
			Digit digit = CharToDigit(c);

			if (ambigious_negative) {
				if (digit == ambigious_digit+1 || digit == ambigious_digit+2) {
					number -= DigitToNumber(ambigious_digit);
				} else {
					number += DigitToNumber(ambigious_digit);
				}
				ambigious_negative = false;
			}

			if (digit == I_1 || digit == X_10 || digit == C_100) {
				ambigious_negative = true;
				ambigious_digit = digit;
			} else {
				number += DigitToNumber(digit);
			}
		}

		if (ambigious_negative) {
			number += DigitToNumber(ambigious_digit);
		}

		return number;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.romanToInt("IV"));
	printf("%d\n", s.romanToInt("XCIX"));
	printf("%d\n", s.romanToInt("MMXIV"));
	return 0;
}
