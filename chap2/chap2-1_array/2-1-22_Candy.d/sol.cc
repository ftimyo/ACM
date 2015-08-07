#include <vector>
#include <numeric> /*for accumulate*/
using namespace std;
class Solution {
public:
	int candy(vector<int>& ratings) {
		auto& r = ratings;
		int n = r.size();
		vector<int> c(n, 0);
		c[0] = 1;
		for (int i = 1; i < n; ++i) {
			if (r[i] > r[i - 1]) c[i] = max(c[i - 1] + 1, c[i]);
			else c[i] = max(1, c[i]);
		}
		for (int i = n - 2; i >= 0; --i) {
			if (r[i] > r[i + 1]) c[i] = max(c[i + 1] + 1, c[i]);
			else c[i] = max(1, c[i]);
		}
		return accumulate(begin(c), end(c), 0);
	}
};
