#include <unordered_map>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seqs;
        int mx_len = 1;
        for (auto n : nums) {
            if (seqs.find(n) != end(seqs)) continue;
            auto& curr = seqs[n] = 1;
            auto left = 0, right = 0, pre = n - 1, next = n + 1;
            if (seqs.find(pre) != end(seqs)) {
                left = seqs[pre];
                curr += left;
            }
            if (seqs.find(next) != end(seqs)) {
                right = seqs[next];
                curr += right;
            }
            seqs[n - left] = seqs[n + right] = curr;
            mx_len = max(curr, mx_len);
        }
        return mx_len;
    }
};
