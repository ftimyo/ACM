#include <string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string res{}; int c = 0;
		if (a.length() > b.length()) a.swap(b);
		auto pa = a.rbegin(), pb = b.rbegin();
		while (pa != a.rend()) {
			auto d = *(pa++) - '0' + *(pb++) - '0' + c;
			c = d / 2; d %= 2;
			res += d + '0';
		}
		while (pb != b.rend()) {
			auto d = *(pb++) - '0' + c;
			c = d / 2; d %= 2;
			res += d + '0';
		}
		if (c) res += c + '0';
		reverse(begin(res), end(res));
		return res;
	}
};
