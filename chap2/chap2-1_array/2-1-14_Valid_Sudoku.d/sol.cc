#include <vector>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		auto& w = board;
		bool used[9];
		auto ck = [&used] (int c) {if (c == '.') return true; c-= '1'; if (used[c]) return false; return used[c] = true;};
		auto reset = [&used] () {fill(begin(used), end(used), false);};

		for (auto& v : w) {
			reset();
			for (auto& x : v) if (!ck(x)) return false;
		}

		for (int i = 0; i < 9; ++i) {
			reset();
			for (int j = 0; j < 9; ++j) if (!ck(w[j][i])) return false;
		}

		for (int sx = 0; sx < 9; sx += 3)
			for (int sy = 0; sy < 9; sy += 3) {
				auto ex = sx + 3, ey = sy + 3;
				reset();
				for (int i = sx; i < ex; ++i)
					for (int j = sy; j < ey; ++j)
						if (!ck(w[i][j])) return false;
			}
		return true;
	}
};
