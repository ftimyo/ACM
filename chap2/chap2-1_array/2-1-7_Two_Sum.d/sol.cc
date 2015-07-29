#include <iterator>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vi; /*val_idx*/
        for (int i = 0; i < nums.size(); ++i) vi[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++i) {
            auto p = vi.find(target - nums[i]);
            if (p == end(vi) || p->second <= i) continue;
            return vector<int>{i + 1, p->second + 1};
        }
        return vector<int>();
    }
};
