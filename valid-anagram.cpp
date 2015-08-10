#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution {
	void Histogram(const string &s, char hist[26])
	{
		fill(hist, hist+26, 0);
		for (char c: s) {
			hist[c-'a'] += 1;
		}
	}
public:
	bool isAnagram(string s, string t) {
		char hists[2][26];
		Histogram(s, hists[0]);
		Histogram(t, hists[1]);
		return equal(hists[0], hists[0]+26, hists[1]);
	}
};

int main(int argc, char const* argv[])
{
	Solution s;
	printf("%d\n", int(s.isAnagram("cat", "car")));
	printf("%d\n", int(s.isAnagram("anagram", "maranag")));
	return 0;
}
