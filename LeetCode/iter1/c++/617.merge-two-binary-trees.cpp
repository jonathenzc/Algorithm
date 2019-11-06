/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL) {
			return NULL;
		}
	
		TreeNode *ret = new TreeNode((t1 != NULL ? t1->val : 0) + (t2 != NULL ? t2->val : 0));
		ret->left = mergeTrees(t1 != NULL ? t1->left : t1, t2 != NULL ? t2->left : t2);
		ret->right = mergeTrees(t1 != NULL ? t1->right : t1, t2 != NULL ? t2->right : t2);

		return ret;
    }
};
// @lc code=end

