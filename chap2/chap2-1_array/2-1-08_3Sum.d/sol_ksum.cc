#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > ret{};
		if (nums.size() < 3) return ret;
		int target = 0;
		sort(begin(nums), end(nums));
		for (auto i = begin(nums); i < prev(end(nums), 2); ++i) {
			while (i > begin(nums) && *i == *prev(i)) ++i;
			for (auto j = next(i), k = prev(end(nums)); j < k;) {
				if (*i + *j + *k < target) while(++j < k && *j == *prev(j));
				else if (*i + *j + *k > target) while(j < --k && *k == *next(k));
				else {
					ret.push_back({*i, *j, *k});
					while(++j < k && *j == *prev(j));
					while(j < --k && *k == *next(k));
				}
			}
		}
		return ret;
	}
};
