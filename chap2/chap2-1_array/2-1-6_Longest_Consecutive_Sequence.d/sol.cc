#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        auto max_len = 0;
        for (auto n : nums) used[n] = false;
        
        for (auto n : nums) {
            auto len = 1;
            if (used[n]) continue;
            for (auto j = n + 1; used.find(j) != end(used); ++j) {
                ++len;
                used[j] = true;
            }
            for (auto j = n - 1; used.find(j) != end(used); --j) {
                ++len;
                used[j] = true;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
