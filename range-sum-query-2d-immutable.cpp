#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class NumMatrix {
	vector<int> integral;
	size_t W;
	public:
	NumMatrix(const vector<vector<int>> &matrix) {
		if (matrix.size() == 0 or matrix[0].size() == 0) {
			return;
		}
		const size_t h = matrix.size();
		const size_t w = matrix[0].size();
		integral.resize((w+1)*(h+1));
		W = w+1;
		fill(integral.begin(), integral.begin()+W, 0);
		for (size_t y = 0; y < h; ++y) {
			int sum = 0;
			int *prev = &integral[W*y];
			int *cur = &integral[W*(y+1)];
			*cur = 0;
			++cur;
			++prev;
			for (size_t x = 0; x < w; ++x) {
				sum += matrix[y][x];
				*cur = *prev + sum;
				++cur;
				++prev;
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		++row2;
		++col2;
		return integral[W*row2+col2]-integral[W*row1+col2]-integral[W*row2+col1]+integral[W*row1+col1];
	}
};





int main(int argc, char const* argv[])
{
	NumMatrix n({{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}});
	printf("%d\n", n.sumRegion(2,1,4,3)); // 8
	printf("%d\n", n.sumRegion(1,1,2,2)); // 11
	printf("%d\n", n.sumRegion(1,2,2,4)); // 12
	return 0;
}
