#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		auto c = 1u;
		for (auto p = digits.rbegin(); p < digits.rend(); ++p) {
			*p += c;
			c = *p / 10;
			*p %= 10;
		}
		if (c > 0) digits.insert(begin(digits), c);
		return digits;
	}
};
