#include <bitset>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		const int bits = sizeof(int) * 8;
		vector<int> c(bits, 0);
		for (const auto& x : nums) {
			bitset<bits> n(x);
			for (int i = 0; i < bits; ++i) c[i] = (c[i] + (1 & n[i])) % 3;
		}
		bitset<bits> t(0);
		for (int i = 0; i < bits; ++i)
			if (c[i] > 0) t.set(i);
		return static_cast<int>(t.to_ulong());
	}
};
