#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <array>
#include <cstdio>
using namespace std;

class Solution {
	typedef array<int,26> Histogram;
	struct HistogramHash {
		size_t operator()(const Histogram &histogram) const {
			size_t result = 2166136261;
			for (auto v: histogram) {
				result = (result*16777619) ^ v;
			}
			return result;
		}
	};
	void AnagramTransform(const string &s, Histogram &histogram) {
		fill(histogram.begin(), histogram.end(), 0);
		for (char c: s) {
			histogram[c-'a'] += 1;
		}
	}
public:
	vector<string> anagrams(vector<string>& strs) {
		struct FirstString {
			string s;
			int count;
		};
		Histogram histogram;
		vector<string> ret;
		unordered_map<Histogram, FirstString, HistogramHash> um;
		for (auto &str: strs) {
			AnagramTransform(str, histogram);
			auto insert_result = um.insert({histogram, {str, 1}});
			if (!insert_result.second) {
				auto exist_it = insert_result.first;
				int &exist_count = exist_it->second.count;
				if (exist_count == 1) {
					// must add the first one as well
					ret.push_back(exist_it->second.s);
				}
				ret.push_back(str);
				++exist_count;
			}
		}
		return ret;
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	vector<string> v{"abc", "fsd", "aab", "ggq", "qqq", "bacc", "bca", "cab", "qq", "qqq"};
	auto ans_strs = s.anagrams(v);
	for (auto &ans_str : ans_strs) {
		printf("%s\n", ans_str.c_str());
	}
	return 0;
}
