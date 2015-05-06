#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
	// copied from wiki
	long long int GCD(long long int u, long long int v) {
		int shift;
		if (u == 0) return v;
		if (v == 0) return u;
		for (shift = 0; ((u | v) & 1) == 0; ++shift) {
			u >>= 1;
			v >>= 1;
		}
		while ((u & 1) == 0) {
			u >>= 1;
		}
		do {
			while ((v & 1) == 0) {
				v >>= 1;
			}
			if (u > v) {
				long long int t = v; v = u; u = t;
			}
			v = v - u;
		} while (v != 0);
		return u << shift;
	}

	template <int d> long long int ExtractFactor(long long int &n) {
		for (int i = 0; ; ++i) {
			const long long int q = n/d;
			const long long int r = n - q*d;
			if (r == 0) {
				n = q;
			} else {
				return i;
			}
		}
	}

	void CalculateRecurCount(long long int denominator, int &n_recur, int &n_non_recur) {
		const int num_2 = ExtractFactor<2>(denominator);
		const int num_5 = ExtractFactor<5>(denominator);
		n_non_recur = max(num_2, num_5);
		if (denominator == 1) {
			n_recur = 0;
			return;
		}

		long long int r = 0;
		for (int i = 1;; i++) {
			r = (r*10+9) % denominator;
			if (r == 0) {
				n_recur = i;
				break;
			}
		}
	}

	string CalculateNextDigits(long long int &numerator, long long int denominator, int ndigit) {
		stringstream ret;
		long long int num = numerator;
		long long int den = denominator;
		for (int i = 0; i < ndigit; ++i) {
			num *= 10;
			long long int digit = num / den;
			num = num - digit * den;
			ret << digit;
		}
		numerator = num;
		return ret.str();
	}
public:
	string fractionToDecimal(int numerator, int denominator)
	{
		stringstream ret;
		long long int num = numerator;
		long long int den = denominator;
		// Zero?
		if (numerator == 0) {
			return string("0");
		}
		// Negative?
		bool neg = false;
		if (num < 0) {
			neg = !neg;
			num = -num;
		}
		if (den < 0) {
			neg = !neg;
			den = -den;
		}
		if (neg) {
			ret << '-';
		}
		// GCD first
		const long long int gcd = GCD(num, den);
		num /= gcd;
		den /= gcd;
		// Integer
		const long long int integer_part = num / den;
		num = num - integer_part * den;
		ret << integer_part;
		if (num == 0) {
			return ret.str();
		}
		// Calculate recurring count
		int n_non_recur, n_recur;
		CalculateRecurCount(den, n_recur, n_non_recur);
		// Non-recurring part
		string non_recur_part = CalculateNextDigits(num, den, n_non_recur);
		ret << "." << non_recur_part;
		if (n_recur == 0) {
			return ret.str();
		}
		// Recurring part
		string recur_part = CalculateNextDigits(num, den, n_recur);
		ret << "(" << recur_part << ")";
		return ret.str();
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	cout << s.fractionToDecimal(1, 2) << endl;
	cout << s.fractionToDecimal(2, 1) << endl;
	cout << s.fractionToDecimal(2, 3) << endl;
	cout << s.fractionToDecimal(1, 7) << endl;
	cout << s.fractionToDecimal(5, 6) << endl;
	cout << s.fractionToDecimal(-1, -2147483648) << endl;
	return 0;
}
