#include <vector>
#include <iterator>
#include <set>
#include <unordered_map>
/*
 * Avg Time O(n^2), Space O(n^2)
 * worst case O(n^4)
 */
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret{};
		set<vector<int>> one{};
		if (nums.size() < 4) return ret;
		sort(begin(nums), end(nums));
		using itr_pair = pair<decltype(begin(nums)), decltype(begin(nums))>;
		unordered_multimap<int, itr_pair> twoSums;

		/*building the hash table*/
		for (auto i = begin(nums); i < prev(end(nums)); ++i)
			for (auto j = next(i); j < end(nums); ++j) twoSums.insert({*i + *j, {i, j}});

		for (auto i = begin(nums); i < end(nums); ++i) {
			for (auto j = next(i); j < end(nums); ++j) {
				auto delta = target - (*i + *j);
				auto range = twoSums.equal_range(delta);
				for (auto p = range.first; p != range.second; ++p) {
					auto x = p->second.first;
					auto y = p->second.second;
					if (i <= y) continue;
					vector<int> four {*x, *y, *i, *j};
					one.insert(four);
				}
			}
		}
		ret.assign(begin(one), end(one));
		return ret;
	}
};
