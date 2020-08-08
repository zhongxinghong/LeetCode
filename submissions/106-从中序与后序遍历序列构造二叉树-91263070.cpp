/**
 * Submission ID: 91263070
 * Question ID: 106
 * Question Title: 从中序与后序遍历序列构造二叉树
 * Question URL: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Solution Time: 2020-07-25 12:13:29
 * Solution Test Result: 203 / 203
 * Solution Status: Accepted
 * Solution Memory: 17.2 MB
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
        const std::vector<int> &inorder,
        const std::vector<int> &postorder,
        int ist, int ied,
        int pst, int ped)
    {
        if (ist > ied)
            return NULL;

        int i;
        TreeNode *root = new TreeNode(postorder[ped]);

        for (i = ist; i <= ied && inorder[i] != postorder[ped]; ++i)
            ;

        root->left = __buildTree(inorder, postorder, ist, i - 1, pst, pst + i - ist - 1);
        root->right = __buildTree(inorder, postorder, i + 1, ied, i - ied + ped, ped - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int ni = inorder.size(), np = postorder.size();

        if (ni == 0 || np == 0)
            return NULL;

        return __buildTree(inorder, postorder, 0, ni - 1, 0, np - 1);
    }
};
