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
			if (i > begin(nums) && *i == *prev(i)) continue; /*remove duplicate numbers*/
			for (auto j = next(i), k = prev(end(nums)); j != k;) {
				if (j > next(i) && *j == *prev(j)) {++j; continue;}
				if (k < prev(end(nums)) && *k == *next(k)) {--k; continue;}
				auto sum = *i + *j + *k;
				if (sum < target) ++j;
				else if (sum > target) --k;
				else {ret.push_back({*i, *j, *k}); ++j;}
			}
		}
		return ret;
	}
};
