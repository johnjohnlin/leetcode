#include <string>
#include <stack>
#include <cassert>
#include <cstdio>
#include <cctype>
using namespace std;

class Solution {
	struct AstData {
		bool is_number_;
		union {int number_; char operator_;};
	};
	stack<AstData> ast_data_;
	size_t last_token_start_;
	enum LexState {DEFAULT, NUMBER} lex_state_;

	void EmitSymbol(char op) {
		// printf("size %lu\n", ast_data_.size());
		// printf("symb '%c'\n", op);
		if (op == ')') {
			auto num = ast_data_.top().number_;
			ast_data_.pop();
			ast_data_.pop();
			EmitNumber(num);
		} else {
			ast_data_.push(AstData{false, {op}});
		}
		// printf("size %lu\n", ast_data_.size());
	}
	void EmitNumber(int num) {
		// printf("size %lu\n", ast_data_.size());
		// printf("num %d\n", num);
		if (ast_data_.size() == 0) {
			ast_data_.push(AstData{true, {num}});
			return ;
		}
		switch (ast_data_.top().operator_) {
			case '+':
				ast_data_.pop();
				ast_data_.top().number_ += num;
				// printf("+%d\n", num);
				break;
			case '-':
				ast_data_.pop();
				ast_data_.top().number_ -= num;
				// printf("-%d\n", num);
				break;
			default:
				ast_data_.push(AstData{true, {num}});
				// printf(">%d\n", num);
		}
		// printf("size %lu\n", ast_data_.size());
	}
public:
	int calculate(string s) {
		last_token_start_ = 0;
		lex_state_ = DEFAULT;
		bool state_changed = false;
		s.push_back(' ');

		for (size_t i = 0; i < s.size(); ++i) {
			if (state_changed) {
				--i;
				state_changed = false;
			}
			switch (lex_state_) {
				case DEFAULT:
					if (isspace(s[i])) {
						last_token_start_ = i+1;
					} else if (isdigit(s[i])) {
						last_token_start_ = i;
						lex_state_ = NUMBER;
						state_changed = true;
					} else {
						EmitSymbol(s[i]);
						last_token_start_ = i+1;
					}
					break;
				case NUMBER:
					if (!isdigit(s[i])) {
						int number_got = 0;
						for (size_t j = last_token_start_; j < i; ++j) {
							number_got *= 10;
							number_got += s[j] - '0';
						}
						EmitNumber(number_got);
						lex_state_ = DEFAULT;
						state_changed = true;
						last_token_start_ = i+1;
					}
					break;
			}
		}
		assert(ast_data_.size() == 1);
		const int ret = ast_data_.top().number_;
		ast_data_.pop();
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", s.calculate(" 1234+4321")); // 2
	printf("%d\n", s.calculate(" 2-1 + 2 ")); // 3
	printf("%d\n", s.calculate("(1+(4+5+2)-3)+(6+8)")); // 23
	return 0;
}
