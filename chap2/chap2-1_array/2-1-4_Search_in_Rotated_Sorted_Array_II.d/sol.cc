#include <vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int first = 0, last = nums.size();
		while (first != last) {
			auto mid = (first + last) / 2;
			if (nums[mid] == target) return true;
			if (nums[first] < nums[mid]) {
				if (nums[first] <= target && target < nums[mid]) last = mid;
				else first = mid + 1;
			} else if (nums[first] == nums[mid]) {
				++first;
			} else {
				if (nums[mid] < target && target <= nums[last - 1]) first = mid + 1;
				else last = mid;
			}
		}
		return false;
	}
};
