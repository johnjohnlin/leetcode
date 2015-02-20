#include <numeric>
#include <cstdio>
using std::accumulate;

class Solution {
	struct FSM {
		int bitplane1_;

		FSM(int bitplane1 = 0): bitplane1_(bitplane1) {}
		inline FSM& operator=(const FSM &rhs)
		{
			bitplane1_ = rhs.bitplane1_;
			return *this;
		}
		inline FSM operator+(const int rhs)
		{
			return FSM(bitplane1_^rhs);
		}
	};
public:
	int singleNumber(int A[], int n)
	{
		return accumulate(A, A+n, FSM()).bitplane1_;
	}
};

int main(int argc, char const* argv[])
{
	int array[] = {1,5,2,3,1,2,3};
	Solution s;
	printf("%d\n", s.singleNumber(array, sizeof(array)/sizeof(int)));
	return 0;
}
