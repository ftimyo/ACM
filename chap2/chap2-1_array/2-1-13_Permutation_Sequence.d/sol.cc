#include <numeric> /*decl for iota, partial_sum*/
#include <cstdlib> /*decl for div*/
#include <functional> /*decl for function template multiplies*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		string s{};
		vector<bool> ds(10, false);
		int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

		/* calculate factorials
		vector<int> f(10, 1);
		iota(next(begin(f)), end(f), 1);
		partial_sum(next(begin(f)), end(f), next(begin(f)), multiplies<int>());
		*/

		auto q = k - 1 /*cantor encoding starts from 0*/, r = 0;
		for (auto i = n - 1; i >= 0; --i) {
			auto dv = div(q, f[i]);
			q = dv.rem, r = dv.quot;
			auto d = 1;
			for (; d <= n; ++d) {
				if (ds[d]) continue;
				if (r-- == 0) break;
			}
			ds[d] = true;
			s += d + '0';
		}
		return s;
	}
};
