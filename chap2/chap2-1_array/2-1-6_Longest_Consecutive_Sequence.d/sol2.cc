#include <unordered_map>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> q;
		auto lmx = 1;
		for (auto i : nums) {
			if (q.find(i) != end(q)) continue;
			auto n = q.insert({i, 1}).first, right = q.find(i + 1), left = q.find(i - 1);
			if (left != end(q)) left = q.find(i - left->second); else left = n;
			if (right != end(q)) right = q.find(i + right->second); else right = n;
			auto l = left->second = right->second = right->first - left->first + 1;
			lmx = max(l, lmx);
		}
		return lmx;
	}
};
