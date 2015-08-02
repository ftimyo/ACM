#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		auto b = begin(nums);
		auto e = copy_if(b, end(nums), b, [val](int n){if(n != val) return true; else return false;});
		return distance(b, e);
	}
};
