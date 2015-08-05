#include <vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		auto c = 1u; /*carry*/
		for (auto p = digits.rbegin(); p < digits.rend(); ++p)
			if (*p + c > 9) *p = 0; else {++(*p); c = 0; break;}
		if (c != 0) digits.insert(begin(digits), c);
		return digits;
	}
};
