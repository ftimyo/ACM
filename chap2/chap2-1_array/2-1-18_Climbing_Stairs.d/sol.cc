#include <cmath>
class Solution {
public:
	int climbStairs(int n) {
		auto r5 = sqrt(5);
		auto p1 = (1 + r5) / 2.0, p2 = -1 / p1;
		return floor(0.5 + (pow(p1, n + 1) - pow(p2, n + 1)) / r5);
	}
};
