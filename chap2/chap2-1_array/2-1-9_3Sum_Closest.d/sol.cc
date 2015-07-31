#include <vector>
#include <climits> /*for INT_MAX*/
#include <cstdlib> /*for abs; also defined in cmath as 'std::abs'*/
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		/*int d = ~(1 << 31);*/
		int d = INT_MAX;
		sort(begin(nums), end(nums));
		for (auto i = begin(nums); i < end(nums) - 2; ++i) {
			for (auto j = i + 1, k = end(nums) - 1; j < k;) {
				auto delta = target - (*i + *j + *k);
				d = abs(delta) < abs(d) ? delta : d;
				if (delta > 0) ++j;
				else if (delta < 0) --k;
				else { return target; }
			}
		}
		return target - d;
	}
};
