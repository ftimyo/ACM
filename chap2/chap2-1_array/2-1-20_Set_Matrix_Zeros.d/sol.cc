#include <vector>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		auto& x = matrix;
		const int m = x.size();
		if (m < 1) return;
		auto& l = x.front();
		const int n = l.size();
		if (n < 1) return;
		bool cz = false;
		for (auto& v : x) if (v.front() == 0) {cz = true; break;}
		bool rz = false;
		for (auto v : l) if (v == 0) {rz = true; break;}
		for (auto i = 1; i < m; ++i) {
			auto& v = x[i];
			for (auto j = 1; j < n; ++j) if (v[j] == 0) {l[j] = 0; v.front() = 0;}
		}
		for (auto i = 1; i < m; ++i) {
			auto& v = x[i];
			if (v.front() == 0) fill(begin(v), end(v), 0);
		}
		for (auto i = 1; i < n; ++i) {
			if (l[i] == 0) for(auto& v : x) v[i] = 0;
		}
		if (cz) for (auto& v : x) v.front() = 0;
		if (rz) fill(begin(l), end(l), 0);
	}
};
