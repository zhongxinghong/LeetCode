/**
 * Submission ID: 88386410
 * Question ID: 100
 * Question Title: 相同的树
 * Question URL: https://leetcode-cn.com/problems/same-tree/
 * Solution Time: 2020-07-16 16:18:36
 * Solution Test Result: 57 / 57
 * Solution Status: Accepted
 * Solution Memory: 7.7 MB
 * Solution Runtime: 4 ms
 */

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if ((p && !q) || (!p && q))
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
