#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.size() == 0) {
			return true;
		}
		const size_t h = board.size();
		if (h == 0) {
			return false;
		}
		const size_t w = board[0].size();
		const size_t n = word.size();

		enum Direction {TOP,RIGHT,BOTTOM,LEFT,DONE};
		struct BtData { size_t y,x; Direction d; };
		vector<BtData> bt_stack;
		vector<bool> walked(w*h, false);
		for (size_t y = 0; y < h; ++y) {
			for (size_t x = 0; x < w; ++x) {
				if (board[y][x] != word[0]) {
					continue;
				}
				walked[y*w+x] = true;
				bt_stack.push_back({y,x,TOP});
				while (true) {
					const size_t stack_size = bt_stack.size();
					if (stack_size == 0) {
						break;
					} else if (stack_size == n) {
						return true;
					}
					auto &stack_top = bt_stack.back();
					switch(stack_top.d) {
#define TRY_WALK(y,x,next_dir)\
	if (not walked[(y)*w+(x)] and board[y][x] == word[stack_size]) {\
		stack_top.d = next_dir;\
		walked[(y)*w+(x)] = true;\
		bt_stack.push_back({(y),(x),TOP});\
		break;\
	}
						case TOP:
							if (stack_top.y != 0) {
								TRY_WALK(stack_top.y-1, stack_top.x, RIGHT);
							}
						case RIGHT:
							if (stack_top.x != w-1) {
								TRY_WALK(stack_top.y, stack_top.x+1, BOTTOM);
							}
						case BOTTOM:
							if (stack_top.y != h-1) {
								TRY_WALK(stack_top.y+1, stack_top.x, LEFT);
							}
						case LEFT:
							if (stack_top.x != 0) {
								TRY_WALK(stack_top.y, stack_top.x-1, DONE);
							}
						case DONE:
							walked[stack_top.y*w+stack_top.x] = false;
							bt_stack.pop_back();
#undef TRY_WALK
					}
				}
			}
		}
		return false;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<vector<char>> board({
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	});
	printf("%d\n", int(s.exist(board,"ABCCED"))); // 1
	printf("%d\n", int(s.exist(board,"SEE"))); // 1
	printf("%d\n", int(s.exist(board,"ABCB"))); // 0
	return 0;
}
