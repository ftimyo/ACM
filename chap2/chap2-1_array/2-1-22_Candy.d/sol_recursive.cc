#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int> c(n, 0);
		int sum = 0;
		std::function<int (int)> give = [&](int i) {
			if (c[i] == 0) {
				c[i] = 1;
				if (i > 0 && ratings[i] > ratings[i - 1]) c[i] = max(c[i], give(i - 1) + 1);
				if (i < n - 1 && ratings[i] > ratings[i + 1]) c[i] = max(c[i], give(i + 1) + 1);
			}
			return c[i];
		};
		for (int i = 0; i < n; ++i)
			sum += give(i);
		return sum;
	}
};
