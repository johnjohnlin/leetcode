#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cctype>
#include <cstdio>
using namespace std;
inline void PrintVector(const vector<int> &v) {
	for (int num: v) {
		printf("%d ", num);
	}
	puts("~");
}

class Solution {
	void ParseInput(string &input, vector<char> &operators, vector<int> &values) {
		input.push_back('$');
		operators.resize(0);
		values.resize(0);
		int cur_number = 0;
		for (char c: input) {
			if (isdigit(c)) {
				const int digit = c - '0';
				cur_number = cur_number*10 + digit;
			} else {
				values.push_back(cur_number);
				if (c != '$') {
					operators.push_back(c);
					cur_number = 0;
				}
			}
		}
	}
public:
	vector<int> diffWaysToCompute(string input) {
		vector<char> operators;
		vector<int> values;
		ParseInput(input, operators, values);

		const int n = values.size();
		// index 1: length
		// index 2: start
		// index 3: possible results
		vector<vector<vector<int>>> possible_results(n);
		for (int i = 0; i < n; i++) {
			possible_results[i].resize(n-i);
		}
		for (int i = 0; i < n; i++) {
			possible_results[0][i].push_back(values[i]);
		}
		for (int length = 2; length <= n; length++) {
			for (int start = 0; start <= n-length; start++) {
				auto &dp_target = possible_results[length-1][start];
				for (int left_length = 1; left_length < length; left_length++) {
#define OP(op, opc)\
	case opc:\
		for (int a: possible_results[left_length-1][start]) {\
			for (int b: possible_results[length-left_length-1][start+left_length]) {\
				dp_target.push_back(a op b);\
			}\
		}\
		break;
					switch(operators[start+left_length-1]) {
						OP(+, '+')
						OP(-, '-')
						OP(*, '*')
						OP(/, '/')
					}
				}
			}
		}
		return possible_results.back().front();
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	PrintVector(s.diffWaysToCompute("2-1-1"));
	puts("===");
	PrintVector(s.diffWaysToCompute("2*3-4*5"));
	return 0;
}
