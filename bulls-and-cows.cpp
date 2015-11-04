#include <string>
#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>
#include <cassert>
#include <cstdio>
using namespace std;

class Solution {
	public:
		string getHint(const string &secret, const string &guess) {
			int diff[10] = {};
			int a = 0, b = 0;
			const size_t n = guess.size();
			for (size_t i = 0; i < n; ++i) {
				if (guess[i] == secret[i]) {
					++a;
				} else {
					if (diff[guess[i]-'0'] < 0) {
						++b;
					}
					++diff[guess[i]-'0'];
					if (diff[secret[i]-'0'] > 0) {
						++b;
					}
					--diff[secret[i]-'0'];
				}
			}
			stringstream result;
			result << a << 'A' << b << 'B';
			return result.str();
		}
};

int main(int argc, char const* argv[])
{
	Solution s;
	puts(s.getHint("1234", "4321").c_str());
	puts(s.getHint("12345", "54321").c_str());
	puts(s.getHint("12345", "00000").c_str());
	return 0;
}
