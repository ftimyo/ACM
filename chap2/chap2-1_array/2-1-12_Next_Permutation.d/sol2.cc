#include <iterator>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
	template<typename It>
	bool nperm(const It b, const It e) {
		if (b == e) return false;
		auto i = prev(e);
		if (b == i) return false;
		auto j = prev(i);
		for (; *j >= *i && i > b; --i, --j);
		if (i == b) {reverse(b, e); return false;}
		auto v = *j, c = find_if(reverse_iterator<It>(e), reverse_iterator<It>(j), [v](int x){return x > v;});
		iter_swap(j, c); reverse(i, e);
		return true;
	}
public:
	void nextPermutation(vector<int>& nums) {
		nperm(begin(nums), end(nums));
	}
};
