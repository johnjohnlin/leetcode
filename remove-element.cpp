#include <algorithm>
#include <functional>
using namespace std::placeholders;
using std::bind;
using std::equal_to;
using std::remove_if;

class Solution {
public:
	int removeElement(int A[], int n, int elem)
	{
		return remove_if(A, A+n, bind(equal_to<int>(), _1, elem)) - A;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	int array[] = {1, 4, 3, 3, 2, 2, 3, 4};
	int num_left = s.removeElement(array, sizeof(array)/sizeof(int), 3);
	for (int i = 0; i < num_left; ++i) {
		printf("%d\n", array[i]);
	}
	return 0;
}
