/**
 * Submission ID: 88870948
 * Question ID: 114
 * Question Title: 二叉树展开为链表
 * Question URL: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 * Solution Time: 2020-07-18 01:29:02
 * Solution Test Result: 225 / 225
 * Solution Status: Accepted
 * Solution Memory: 12.1 MB
 * Solution Runtime: 12 ms
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
    void flatten(TreeNode* root) {
        TreeNode *p;

        for (; root; root = root->right)
        {
            if ((p = root->left) == NULL)
                continue;

            for (; p->right; p = p->right);
                ;

            p->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};
