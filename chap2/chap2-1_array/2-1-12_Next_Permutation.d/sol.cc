#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_permutation(begin(nums), end(nums));
	}
};