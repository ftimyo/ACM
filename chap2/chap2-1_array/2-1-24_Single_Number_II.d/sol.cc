#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0, three = 0;
		for (auto& x : nums) {
			two |= ~(one ^ x) & x;
			one ^= x;
			three = one & two;
			one &= ~three;
			two &= ~three;
		}
		return one;
	}
};
