#include <numeric>
#include <cstdio>
using std::accumulate;

class Solution {
	struct FSM {
		int bitplane1_, bitplane2_;

		FSM(int bitplane1 = 0, int bitplane2 = 0):
			bitplane1_(bitplane1), bitplane2_(bitplane2) {}
		inline FSM& operator=(const FSM &rhs)
		{
			bitplane1_ = rhs.bitplane1_;
			bitplane2_ = rhs.bitplane2_;
			return *this;
		}
		inline FSM operator+(const int rhs)
		{
			// FSM bitplane 1, 2
			// 00 --> 01 --> 10
			int change_if1_bitplane1 = bitplane1_ | bitplane2_;
			int change_if1_bitplane2 = ~bitplane1_;

			int bitplane1 = bitplane1_ ^ (change_if1_bitplane1 & rhs);
			int bitplane2 = bitplane2_ ^ (change_if1_bitplane2 & rhs);
			return FSM(bitplane1, bitplane2);
		}
	};
public:
	int singleNumber(int A[], int n)
	{
		return accumulate(A, A+n, FSM()).bitplane2_;
	}
};

int main(int argc, char const* argv[])
{
	int array[] = {1,5,2,1,1,5,5};
	Solution s;
	printf("%d\n", s.singleNumber(array, sizeof(array)/sizeof(int)));
	return 0;
}
