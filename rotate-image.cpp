#include <vector>
#include <cstdio>
using std::vector;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix)
	{
		const int n = matrix.size();

		for (int i = 0; i < (n+1)/2; ++i) {
			for (int j = 0; j < n/2; ++j) {
				int v0 = matrix[i][j];
				matrix[    i][    j] = matrix[n-1-j][    i];
				matrix[n-1-j][    i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[    j][n-1-i];
				matrix[    j][n-1-i] = v0;
			}
		}
	}
};

int main(int argc, char const* argv[])
{
	vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution s;
	s.rotate(matrix);
	for (auto row: matrix) {
		for (int e: row) {
			printf("%d ", e);
		}
		putchar('\n');
	}
	return 0;
}
