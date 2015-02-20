#include <cstdio>
#include <cctype>
#include <vector>
using std::vector;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int y = 0; y < 9; y++) {
			bool check[9] = {};
			for (int x = 0; x < 9; x++) {
				if (isdigit(board[x][y])) {
					int digit_number = board[x][y] - '1';
					if (check[digit_number]) {
						return false;
					} else {
						check[digit_number] = true;
					}
				}
			}
		}

		for (int y = 0; y < 9; y++) {
			bool check[9] = {};
			for (int x = 0; x < 9; x++) {
				if (isdigit(board[y][x])) {
					int digit_number = board[y][x] - '1';
					if (check[digit_number]) {
						return false;
					} else {
						check[digit_number] = true;
					}
				}
			}
		}

		for (int base_y = 0; base_y < 9; base_y += 3) {
			for (int base_x = 0; base_x < 9; base_x += 3) {
				bool check[9] = {};
				for (int y = base_y + 0; y < base_y + 3; y++) {
					for (int x = base_x + 0; x < base_x + 3; x++) {
						if (isdigit(board[y][x])) {
							int digit_number = board[y][x] - '1';
							if (check[digit_number]) {
								return false;
							} else {
								check[digit_number] = true;
							}
						}
					}
				}
			}
		}

		return true;
	}
};

int main(int argc, char const* argv[])
{
	const char *p[] = {
		".87654321",
		"2........",
		"3........",
		"4........",
		"5........",
		"6........",
		"7........",
		"8........",
		"9........"
	};
	Solution s;
	vector<vector<char>> board = {
		{p[0], p[0]+9},
		{p[1], p[1]+9},
		{p[2], p[2]+9},
		{p[3], p[3]+9},
		{p[4], p[4]+9},
		{p[5], p[5]+9},
		{p[6], p[6]+9},
		{p[7], p[7]+9},
		{p[8], p[8]+9}
	};
	printf("%d\n", int(s.isValidSudoku(board)));
	return 0;
}
