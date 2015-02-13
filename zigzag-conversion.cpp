#include <cstdio>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
	static void DoCopy(const char *src, char *dst, const int src_stride, const int dst_stride, const int n)
	{
		for (int i = 0; i < n; ++i) {
			*dst = *src;
			src += src_stride;
			dst += dst_stride;
		}
	}
public:
	string convert(const string &s, int nRows) {
		if (nRows == 1 || s.size() == 0) {
			return s;
		}

		const int chunk_size = nRows*2 -2;
		const int n_chunk = s.size() / chunk_size;
		const int n_left = s.size() - n_chunk * chunk_size;
		vector<char> result(s.size(), '*');
		// 1   1   1
		// 2  22  22
		// 2 2 2 2 2 ...
		// 22  22  2
		// 3   3   3

		char *dst = result.data();

		// part 1
		int n_copy = n_chunk+(0 < n_left? 1: 0);
		DoCopy(s.data(), dst, chunk_size, 1, n_copy);
		dst += n_copy;
		// printf("%s\n", string(result.data(), result.size()).c_str());

		// part 2
		for (int i = 1; i < nRows-1; ++i) {
			// the left one
			const int i_l = i;
			int n_copy_l = n_chunk + (i_l < n_left? 1: 0);
			DoCopy(s.data()+i_l, dst, chunk_size, 2, n_copy_l);
			// printf("%s\n", string(result.data(), result.size()).c_str());

			// the right one
			const int i_r = chunk_size - i;
			int n_copy_r = n_chunk + (i_r < n_left? 1: 0);
			DoCopy(s.data()+i_r, dst+1, chunk_size, 2, n_copy_r);
			// printf("%s\n", string(result.data(), result.size()).c_str());

			dst += n_copy_l + n_copy_r;
		}

		// part 3
		DoCopy(s.data()+nRows-1, dst, chunk_size, 1, n_chunk+(nRows-1<n_left? 1: 0));
		// printf("%s\n", string(result.data(), result.size()).c_str());

		return string(result.data(), result.size());
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("==\n%s\n", s.convert(string("PAYPALISHIRING"), 3).c_str());
	printf("==\n%s\n", s.convert(string(""), 1).c_str());
	return 0;
}
