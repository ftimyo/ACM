#include <climits>
#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int sn = 1, base = 10;
		/*remove white space*/
		str.erase(begin(str), find_if_not(begin(str), end(str), ::isspace));
		if (str.empty()) return 0;
		/*get sign prefix p*/
		auto h = find_if(begin(str), end(str), ::isdigit);
		string p {begin(str), h}; str.erase(begin(str), h);
		if (str.empty()) return 0;
		if (p.length() == 1) {if (p[0] == '-') sn = -1; else if (p[0] != '+') return 0;}
		else if (!p.empty()) return 0;
		/*remove trailing non-digit chars*/
		str.erase(find_if_not(begin(str), end(str), ::isdigit), end(str));
		if (str.empty()) return 0;

		int sum = 0;
		for (auto c : str) {
			c -= '0';
			if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && c > INT_MAX % 10))
				return sn > 0 ? INT_MAX : INT_MIN;
			sum = sum * base + c;
		}
		return sum * sn;
	}
};
