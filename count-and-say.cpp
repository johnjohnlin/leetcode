#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using std::swap;
using std::vector;
using std::string;

class Solution {
	int UpdateRepeat(int count, char number)
	{
		int dst_size = dst->size();
		int num_left = dst_size - dst_write_position;
		int num_write = snprintf(dst->data()+dst_write_position, num_left, "%d%c", count, number);

		if (num_write == num_left) {
			dst->resize(dst->size()*2);
		}

		// It's ok using sprintf because we initialized with enough size
		// So doubling will ensure enough space
		sprintf(dst->data()+dst_write_position, "%d%c", count, number);
		dst_write_position += num_write;
	}

	vector<char> v1;
	vector<char> v2;
	vector<char> *src, *dst;
	size_t dst_write_position;

public:
	string countAndSay(int n)
	{
		v1.resize(16);
		v2.resize(16);

		v1[0] = '1';
		v1[1] = '\0';

		src = &v1;
		dst = &v2;

		for (int i = 1; i < n; i++) {
			dst_write_position = 0;
			char *src_ptr = src->data();
			char repeated_char = *src_ptr;
			int repeated_count = 0;

			while (*src_ptr != '\0') {
				char c = *src_ptr;
				if (repeated_char != c) {
					UpdateRepeat(repeated_count, repeated_char);
					repeated_count = 1;
					repeated_char = c;
				} else {
					++repeated_count;
				}
				++src_ptr;
			}
			UpdateRepeat(repeated_count, repeated_char);

			puts(dst->data());
			swap(dst, src);
		}

		return string(src->data());
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	s.countAndSay(10);
	return 0;
}
