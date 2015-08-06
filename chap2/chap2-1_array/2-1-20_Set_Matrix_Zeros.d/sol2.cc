#include <vector>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		auto& x = matrix;
		const int m = x.size();
		if (m < 1) return;
		const int n = x.front().size();
		if (n < 1) return;
		vector<bool> cz(n, false), rz(m, false);
		for (auto i = 0; i < m; ++i)
			for (auto j = 0; j < n; ++j)
				if (x[i][j] == 0) {cz[j] = true; rz[i] = true;}
		for (auto i = 0; i < m; ++i)
			if (rz[i]) for (auto& v :  x[i]) v = 0;
		for (auto j = 0; j < n; ++j)
			if (cz[j]) for (auto& v : x) v[j] = 0;
	}
};
