/**
 * Submission ID: 88648340
 * Question ID: 105
 * Question Title: 从前序与中序遍历序列构造二叉树
 * Question URL: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Solution Time: 2020-07-17 13:26:28
 * Solution Test Result: 203 / 203
 * Solution Status: Accepted
 * Solution Memory: 17.3 MB
 * Solution Runtime: 44 ms
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

    TreeNode *__buildTree(
        const std::vector<int> &preorder,
        const std::vector<int> &inorder,
        int pst, int ped,
        int ist, int ied)
    {
        int i;

        if (ist >= ied)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pst]);

        for (i = ist; i < ied && inorder[i] != preorder[pst]; ++i)
            ;

        root->left = __buildTree(preorder, inorder, pst + 1, pst + 1 + i - ist, ist, i);
        root->right = __buildTree(preorder, inorder, pst + 1 + i - ist, ped, i + 1, ied);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        return __buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
