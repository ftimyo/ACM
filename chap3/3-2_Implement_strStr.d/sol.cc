#include <string>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty() && needle.empty()) return 0;
		if (needle.empty()) return 0;
		int d = haystack.length() - needle.length(); if (d < 0) return -1;
		auto e = next(begin(haystack), d);
		for (auto s = begin(haystack); s <= e; ++s) {
			auto x = s, y = begin(needle);
			auto p = true;
			while (end(needle) != y) if (*(x++) != *(y++)) {p = false; break;}
			if (p) return distance(begin(haystack), s);
		}
		return -1;
	}
};
