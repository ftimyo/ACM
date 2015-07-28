#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       auto first = begin(nums);
       auto last = end(nums);
       auto out = first;

       while (first != last) {
           auto upper = upper_bound(first, last, *first);
           if (distance(first, upper) > 2) out = copy_n(first, 2, out);
           else out = copy(first, upper, out);

           first = upper;
       }
       return distance(begin(nums), out);
    }
};
