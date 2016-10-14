#include <stack>
#include <vector>
/**
 * Definition for a binary tree node.
*/
struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 */
class Solution {
public:
	std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
		std::vector<std::vector<int>> ret;
		if (root == nullptr) return ret;
		std::vector<std::stack<TreeNode*>> q(2);
		int i = 0;
		q[i].push(root);
		while (!q[i].empty()) {
			auto& qx = q[i];
			auto& qy = q[1^i];
			std::vector<int> lev;
			while(!qx.empty()) {
				auto p = qx.top(); qx.pop();
				lev.push_back(p->val);
				if (i == 0) {
					if (p->left) qy.push(p->left);
					if (p->right) qy.push(p->right);
				} else {
					if (p->right) qy.push(p->right);
					if (p->left) qy.push(p->left);
				}
			}
			ret.push_back(std::move(lev));
			i^=1;
		}
		return ret;
	}
};
