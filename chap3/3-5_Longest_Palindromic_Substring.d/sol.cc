#include <string>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		auto str = s.c_str();
		auto n = s.size();
		decltype(n) maxlen = 1;
		int idx = 0;
		bool p[n][n];
		fill_n(*p,n*n,false);
		for (decltype(n) i = 0; i < n; ++i) {
			p[i][i] = true;
			for (decltype(n) j = 0; j < i; ++j) {
				p[j][i] = (str[i] == str[j]) && (i - j < 2 || p[j+1][i-1]);
				if (p[j][i] && i - j + 1 > maxlen) {
					maxlen = i - j + 1;
					idx = j;
				}
			}
		}
		return s.substr(idx,maxlen);
	}
};
