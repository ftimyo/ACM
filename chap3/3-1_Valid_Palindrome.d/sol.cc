#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() < 2) return true;
		transform(begin(s), end(s), begin(s), ::tolower);
		auto l = begin(s), r = prev(end(s));
		while (l < r) {
			if (!isalnum(*l)) ++l;
			else if (!isalnum(*r)) --r;
			else if (*l != *r) return false;
			else {++l; --r;}
		}
		return true;
	}
};
