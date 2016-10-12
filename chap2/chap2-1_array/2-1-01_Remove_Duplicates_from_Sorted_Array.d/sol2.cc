#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		auto i1 = next(begin(nums));
		for (auto i2 = i1; i2 < end(nums); ++i2) {
				if (*prev(i1) != *i2) {*i1 = *i2; ++i1;}
		}
		return distance(begin(nums),i1);
	}
};
