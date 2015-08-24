#include <climits>
#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int sn = 1, base = 10;
		auto high = INT_MAX / base, low = INT_MAX % base;

		/*remove white spaces*/
		str.erase(begin(str), find_if_not(begin(str), end(str), ::isspace));
		if (str.empty()) return 0;

		/*extract sign*/
		auto h = find_if(begin(str), end(str), ::isdigit);
		string p{begin(str), h}; str.erase(begin(str), h);
		str.erase(find_if_not(begin(str), end(str), ::isdigit), end(str));
		if (str.empty()) return 0;
		if (p.length() == 1) {if (p.front() == '-') sn = -1; else if (p.front() != '+') return 0;}
		else if (!p.empty()) return 0;

		/*extract number*/
		int sum = 0;
		for (auto c : str) {
			c -= '0';

			if (sum > high || (sum == high && c > low))
				return sn > 0 ? INT_MAX : INT_MIN;

			sum = sum * base + c;
		}
		return sum * sn;
	}
};
