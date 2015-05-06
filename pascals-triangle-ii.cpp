#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> buffer1(rowIndex+1);
		buffer1[0] = 1;
		vector<int> buffer2(rowIndex+1);
		vector<int> *src = &buffer1, *dst = &buffer2;
		for (int i = 0; i < rowIndex; ++i) {
			transform(src->begin(), src->begin()+i, src->begin()+1, dst->begin()+1, plus<int>());
			(*dst)[0] = (*dst)[i+1] = 1;
			swap(dst, src);
		}
		return *src;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	for (int i = 0; i < 10; i++) {
		auto ans = s.getRow(i);
		for (auto a: ans) {
			printf("%d,", a);
		}
		putchar('\n');
	}
	return 0;
}
