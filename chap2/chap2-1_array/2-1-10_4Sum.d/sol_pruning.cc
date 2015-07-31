#include <vector>
#include <iterator>
/* Avg Time O(n3), Space O(1)
 * This can be viewed as an improvement of KSum solution (finally based on 2Sum).
 * The improvement is the pruning. But in the worst case, it's the same as KSum,
 * which is O(n3).
 */
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret{};
		if (nums.size() < 4) return ret;
		sort(begin(nums), end(nums));
		for (auto i = begin(nums), imx = prev(end(nums)); i < prev(imx, 2); ++i) {
			if (*i + *next(i) + *next(i, 2) + *next(i, 3) > target) break;
			/*pruning: remove numbers that are too small or too large*/
			while ((i > begin(nums) && *i == *prev(i)) || *i + *prev(imx, 2) + *prev(imx) + *imx < target) ++i;
			const auto iv = *i;
			while (iv + *next(i) + *next(i, 2) + *imx > target) --imx;

			for (auto j = next(i), jmx = imx; j < prev(jmx); ++j) {
				if (iv + *j + *next(j) + *next(j, 2) > target) break;
				while ((j > next(i) && *j == *prev(j)) || iv + *j + *prev(jmx) + *jmx < target) ++j;
				const auto jv = *j;
				while (iv + jv + *next(j) + *jmx > target) --jmx;
				auto ijsum = iv + jv;

				for (auto k = next(j), l = jmx; k < l;) {
					if (ijsum + *k + *l < target) while (++k < l && *k == *prev(k));
					else if (ijsum + *k + *l > target) while (k < --l && *l == *next(l));
					else {
						ret.push_back({iv, jv, *k, *l});
						while (++k < l && *k == *prev(k));
						while (k < --l && *l == *next(l));
					}
				}
			}
		}
		return ret;
	}
};
