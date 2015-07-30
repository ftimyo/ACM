#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret{};
        if (nums.size() < 3) return ret;
        int target = 0;
        auto b = begin(nums), e = end(nums);
        sort(b, e);
        for (auto i = b; i < e - 2; ++i) {
            if (i > b && *i == *(i-1)) continue; /*remove duplicate numbers*/
            for (auto j = i + 1, k = e - 1; j != k;) {
                if (j > i + 1 && *j == *(j-1)) {++j; continue;} /*remove duplicate numbers*/
                if (k < e - 1 && *k == *(k+1)) {--k; continue;} /*remove duplicate numbers*/
                auto sum = *i + *j + *k;
                if (sum < target) ++j;
                else if (sum > target) --k;
                else {ret.push_back({*i, *j, *k}); ++j;}
            }
        }
        return ret;
    }
};
