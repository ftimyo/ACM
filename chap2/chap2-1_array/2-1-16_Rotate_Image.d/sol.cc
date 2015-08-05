#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		auto& m = matrix;
		const auto n = m.size(), x = n - 1u;
		if (n < 2) return;
		for (auto& v : m) reverse(begin(v), end(v));
		for (auto r = 0u; r < n; ++r) {
			for (auto c = 0u; c < n - r; ++c)
				swap(m[r][c], m[x - c][x -r]);
		}
	}
};
