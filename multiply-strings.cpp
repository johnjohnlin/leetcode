#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;

class Solution {
	static int GetDigitRoutine(vector<int> &v, size_t pos) {
		while (pos >= v.size()) {
			v.push_back(0);
		}
		return v[pos];
	}
public:
	string multiply(string num1, string num2) {
		string zero("0");
		if (num1 == zero | num2 == zero) {
			return zero;
		}

		vector<int> num2_int(num2.rbegin(), num2.rend());
		vector<int> product;
		transform(num2_int.begin(), num2_int.end(), num2_int.begin(), [](int x){return x-'0';});
		for (size_t i = 0; i < num1.size(); ++i) {
			const int digit1 = num1[num1.size()-1-i]-'0';
			if (digit1) {
				int carry = 0;
				size_t j;
				for (j = 0; j < num2_int.size(); ++j) {
					assert(carry < 10);
					const int pos = i+j;
					const int original = GetDigitRoutine(product, pos);
					const int result = original + carry + num2_int[j]*digit1;
					carry = result/10;
					product[pos] = result - carry*10;
				}
				while (carry) {
					assert(carry < 10);
					const int pos = i+j;
					const int original = GetDigitRoutine(product, pos);
					const int result = carry + original;
					carry = result/10;
					product[pos] = result - carry*10;
				}
				// for (int x: product) {
				// 	putchar('0'+x);
				// }
				// putchar('~');
				// putchar('\n');
			}
		}
		transform(product.begin(), product.end(), product.begin(), [](int x){return x+'0';});
		return string(product.rbegin(), product.rend());
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%s\n", s.multiply("1234", "789").c_str()); // 973626
	return 0;
}
