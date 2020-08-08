/**
 * Submission ID: 88264234
 * Question ID: 988
 * Question Title: 翻转等价二叉树
 * Question URL: https://leetcode-cn.com/problems/flip-equivalent-binary-trees/
 * Solution Time: 2020-07-16 09:48:43
 * Solution Test Result: 72 / 72
 * Solution Status: Accepted
 * Solution Memory: 11.9 MB
 * Solution Runtime: 8 ms
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

    bool flipEquiv(TreeNode* p, TreeNode* q) {
        TreeNode *p1, *p2, *q1, *q2;

        if (!p && !q)
            return true;

        if ((p && !q) || (!p && q) || (p->val != q->val))
            return false;

        p1 = p->left; p2 = p->right;
        q1 = q->left; q2 = q->right;

        if (!p2 || (p1 && p1->val > p2->val))
            std::swap(p1, p2);

        if (!q2 || (q1 && q1->val > q2->val))
            std::swap(q1, q2);

        return flipEquiv(p1, q1) && flipEquiv(p2, q2);
    }
};
