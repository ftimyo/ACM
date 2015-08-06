#include <vector>
using namespace std;
/*grapcode
 *gn = n ^ (n/2)
 */
class Solution {
public:
	vector<int> grayCode(int n) {
		n = 1 << n;
		vector<int> o;
		for (auto i = 0; i < n; ++i)
			o.push_back(i^(i>>1));
		return o;
	}
};
