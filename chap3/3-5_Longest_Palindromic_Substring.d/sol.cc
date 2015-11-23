#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		auto len = s.length();
		if (len <= 1) return s;

		int max_len = 0, max_start = 0;
		bool f[len][len];

		for (size_t l = 0; l < len; ++l) {
			for (size_t i = 0; i < len - l; ++i) {
				auto j = i + l;
				f[i][j] = (j == i) || (s[i] == s[j] && (l == 1 || f[i+1][j-1]));
				if (f[i][j]) {max_start = i; max_len = l;}
			}
		}
		return s.substr(max_start, max_len+1);
	}
};
