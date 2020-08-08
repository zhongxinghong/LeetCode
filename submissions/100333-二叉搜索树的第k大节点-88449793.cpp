/**
 * Submission ID: 88449793
 * Question ID: 100333
 * Question Title: 二叉搜索树的第k大节点
 * Question URL: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 * Solution Time: 2020-07-16 19:45:32
 * Solution Test Result: 91 / 91
 * Solution Status: Accepted
 * Solution Memory: 24 MB
 * Solution Runtime: 28 ms
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

    void __kthLargest(const TreeNode *root, int &i, const int &k, int &ret)
    {
        if (!root || i > k)
            return;

        __kthLargest(root->right, i, k, ret);

        if (i++ == k)
        {
            ret = root->val;
            return;
        }

        __kthLargest(root->left, i, k, ret);
    }

    int kthLargest(TreeNode* root, int k) {
        int i = 1, ret = 0;
        __kthLargest(root, i, k, ret);
        return ret;
    }
};
