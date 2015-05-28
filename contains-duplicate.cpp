#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Hash {
	constexpr static int NUM_HASH_BIN = 128;
	static int int_hash(int x) {
		x *= 2654435761;
		x &= 127;
		assert(x < NUM_HASH_BIN);
		return x;
	}
};

class Solution {
public:
	bool containsDuplicate(const vector<int>& nums) {
		vector<int> hash_bins[Hash::NUM_HASH_BIN];
		for (int num: nums) {
			int h = Hash::int_hash(num);
			vector<int> &search_me = hash_bins[h];
			if (find(search_me.begin(), search_me.end(), num) == search_me.end()) {
				search_me.push_back(num);
			} else {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", (int)s.containsDuplicate({1,2,3,4,5}));
	printf("%d\n", (int)s.containsDuplicate({1,2,3,1,4,5}));
	return 0;
}
