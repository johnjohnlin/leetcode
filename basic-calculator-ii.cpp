#include "template_matrix.h"
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	enum TokenType: int { ADD= -1, SUB=-2, MUL=-3, DIV=-4, END=-5 };

	vector<int> Parse(const string &s) {
		vector<int> tokens{0};
		for (char c: s) {
			if (isspace(c)) {
				continue;
			}
			switch (c) {
				case '+': tokens.push_back(TokenType::ADD); break;
				case '-': tokens.push_back(TokenType::SUB); break;
				case '*': tokens.push_back(TokenType::MUL); break;
				case '/': tokens.push_back(TokenType::DIV); break;
				default:
					if (tokens.back() < 0) {
						tokens.push_back(0);
					}
					tokens.back() = tokens.back()*10 + c - '0';
			}
		}
		tokens.push_back(TokenType::END);
		return tokens;
	}

	int Calculate(const vector<int> &tokens) {
		stack<int> s;
		s.push(0);
		s.push(TokenType::ADD);
		for (int token: tokens) {
			if (token >= 0) {
				if (s.top() == TokenType::MUL) {
					s.pop();
					s.top() *= token;
				} else if(s.top() == TokenType::DIV) {
					s.pop();
					s.top() /= token;
				} else {
					s.push(token);
				}
			} else {
				if (token == TokenType::ADD || token == TokenType::SUB || token == TokenType::END) {
					const int num = s.top(); s.pop();
					const int op = s.top(); s.pop();
					if (op == TokenType::ADD) {
						s.top() += num;
					} else {
						s.top() -= num;
					}
					if (token == TokenType::END) {
						break;
					}
				}
				s.push(token);
			}
		}
		return s.top();
	}
public:
	int calculate(const string &s) {
		return Calculate(Parse(s));
	}

};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.calculate("3+2*2"));
	printf("%d\n", s.calculate(" 3/2 "));
	printf("%d\n", s.calculate(" 3+5 /2"));
	return 0;
}
