/**
 * Submission ID: 89062129
 * Question ID: 1544
 * Question Title: 统计二叉树中好节点的数目
 * Question URL: https://leetcode-cn.com/problems/count-good-nodes-in-binary-tree/
 * Solution Time: 2020-07-18 17:35:47
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 86.3 MB
 * Solution Runtime: 240 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void __goodNodes(TreeNode *root, int cmax, int &cnt)
    {
        if (root->val >= cmax)
        {
            cnt++;
            cmax = root->val;
        }

        if (root->left)
            __goodNodes(root->left, cmax, cnt);

        if (root->right)
            __goodNodes(root->right, cmax, cnt);
    }

    int goodNodes(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int cnt = 0;
        __goodNodes(root, root->val, cnt);

        return cnt;
    }
};
