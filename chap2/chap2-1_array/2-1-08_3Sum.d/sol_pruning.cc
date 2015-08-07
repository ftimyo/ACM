#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > ret{};
		if (nums.size() < 3) return ret;
		int target = 0;
		sort(begin(nums), end(nums));

		for (auto i = begin(nums), imx = prev(end(nums)); i < prev(imx); ++i) {
			if (*i + *next(i) + *next(i, 2) > target) break;
			while ((i > begin(nums) && *i == *prev(i)) || *i + *prev(imx) + *imx < target) ++i;
			auto iv = *i;
			while (iv + *next(i) + *imx > target) --imx;

			for (auto j = next(i), k = imx; j < k;) {
				if (iv + *j + *k < target) while(++j < k && *j == *prev(j));
				else if (iv + *j + *k > target) while(j < --k && *k == *next(k));
				else {
					ret.push_back({iv, *j, *k});
					while(++j < k && *j == *prev(j));
					while(j < --k && *k == *next(k));
				}
			}
		}
		return ret;
	}
};
