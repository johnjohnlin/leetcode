#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdint>
using namespace std;

class Solution {
	static const size_t REPEAT_LEN;
	static const size_t DNA_CHAR_BIT;
	static const size_t DNA_CHAR_MASK;
	static const size_t DNA_STRING_MASK;
	static const char dna_cstring[];
	uint32_t CharToDnaNum(const char c)
	{
		return find(dna_cstring, dna_cstring+(1<<DNA_CHAR_BIT), c) - dna_cstring;
	}
	string U32ToString(uint32_t u)
	{
		string s(REPEAT_LEN, '\0');
		for (size_t i = 0; i < REPEAT_LEN; ++i) {
			const size_t shamt = DNA_CHAR_BIT*(REPEAT_LEN-1-i);
			s[i] = dna_cstring[(u >> shamt) & DNA_CHAR_MASK];
		}
		return s;
	}
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ret;
		if (s.size() < REPEAT_LEN) {
			return ret;
		}
		unordered_map<uint32_t, unsigned> dna_int_and_counts;
		uint32_t dna_int = 0;
		for (size_t i = 0; i < REPEAT_LEN-1; ++i) {
			dna_int <<= DNA_CHAR_BIT;
			dna_int |= CharToDnaNum(s[i]);
		}
		for (size_t i = REPEAT_LEN-1; i < s.size(); ++i) {
			dna_int <<= DNA_CHAR_BIT;
			dna_int |= CharToDnaNum(s[i]);
			dna_int &= DNA_STRING_MASK;
			auto it_and_success = dna_int_and_counts.insert(make_pair(dna_int, 1));
			if (!it_and_success.second) {
				// already exists
				it_and_success.first->second += 1;
			}
		}
		for (auto &dna_int_and_count: dna_int_and_counts) {
			if (dna_int_and_count.second > 1) {
				ret.push_back(U32ToString(dna_int_and_count.first));
			}
		}
		return ret;
	}
};

const size_t Solution::REPEAT_LEN = 10;
const size_t Solution::DNA_CHAR_BIT = 2;
const size_t Solution::DNA_CHAR_MASK = (1<<DNA_CHAR_BIT)-1;
const size_t Solution::DNA_STRING_MASK = (1<<(DNA_CHAR_BIT*REPEAT_LEN))-1;
const char Solution::dna_cstring[] = {'A','T','C','G'};

int main(int argc, char const* argv[])
{
	Solution s;
	auto ans_str = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (auto &a: ans_str) {
		printf("%s\n", a.c_str());
	}
	return 0;
}
