#include <vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int i = 0;
		const int n = gas.size();
		auto t = n;
		while (t-- > 0) {
			auto sum = 0, c = 0;
			while (c < n) {
				sum += gas[i] - cost[i];
				i = (i + 1) % n;
				if (sum < 0) break;
				++c;
			}
			if (c == n) return i;
		}
		return -1;
	}
};
