#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		auto mx = max_element(begin(height), end(height));
		auto c = 0;
		if (mx == end(height)) return c;
		for (auto p = begin(height), h = p; p < mx; ++p)
			if (*p > *h) h = p;
			else c += *h - *p;
		for (auto p = prev(end(height)), h = p; p > mx; --p)
			if (*p > *h) h = p;
			else c += *h - *p;
		return c;
	}
};
