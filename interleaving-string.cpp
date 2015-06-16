#include <string>
#include <memory>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		const size_t n1 = s1.size();
		const size_t n2 = s2.size();
		const size_t n3 = s3.size();
		if (n3 != n1+n2) {
			return false;
		}
		// logically table[n1+1][n2+1]
		// table[i1][i2] is true if using the first i1 char
		// of s1 and i2 characters of s2 can make the first
		// (i1+i2) characters of s3
		const size_t w = n2+1;
		const size_t h = n1+1;
		unique_ptr<bool[]> dp_table(new bool[w*h]);
		// DP, the first row
		dp_table[w*0+0] = true; // i1 == i2 == 0 is true
		for (size_t i2 = 1; i2 < w; ++i2) {
			dp_table[w*0+i2] = dp_table[w*0+(i2-1)] and s2[i2-1] == s3[i2-1]; // can_advance_s2 when i1 == 0
		}
		for (size_t i1 = 1; i1 < h; ++i1) {
			dp_table[w*i1+0] = dp_table[w*(i1-1)+0] and s1[i1-1] == s3[i1-1]; // can_advance_s1 when i2 == 0
			for (size_t i2 = 1; i2 < w; ++i2) {
				const bool can_advance_s1 = dp_table[w*(i1-1)+(i2  )] and s1[i1-1] == s3[i1+i2-1];
				const bool can_advance_s2 = dp_table[w*(i1  )+(i2-1)] and s2[i2-1] == s3[i1+i2-1];
				dp_table[w*i1+i2] = can_advance_s1 or can_advance_s2;
			}
		}
		return dp_table[w*h-1];
	}
};


int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", (bool)s.isInterleave("aabcc", "dbbca", "aadbbcbcac")); // 1
	printf("%d\n", (bool)s.isInterleave("aabcc", "dbbca", "aadbbbaccc")); // 0
	printf("%d\n", (bool)s.isInterleave("aacaaac", "abbacb", "aaacbbacacaba")); // 0
	return 0;
}
