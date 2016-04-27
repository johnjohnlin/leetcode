#include "template_matrix.h"
#include "template_tree.h"
#include "template_list.h"
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		++num;
		vector<int> ret(num);
		ret[0] = 0;
		int done = 1;
		while (done < num) {
			int n_todo = min(num-done, done);
			transform(ret.begin(), ret.begin()+n_todo, ret.begin()+done, [](int x){return x+1;});
			done *= 2;
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	PrintVector(s.countBits(9));
	return 0;
}
