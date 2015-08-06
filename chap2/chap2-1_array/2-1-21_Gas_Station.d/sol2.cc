#include <vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0, sum = 0, s = 0;
		for (auto i = 0u; i < gas.size(); ++i) {
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0) {
				sum = 0; s = i + 1;
			}
		}
		return total >= 0 ? s : -1;
	}
};
