/**
 * Submission ID: 91273274
 * Question ID: 144
 * Question Title: 二叉树的前序遍历
 * Question URL: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * Solution Time: 2020-07-25 13:17:54
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 0 ms
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> ret;
        std::stack<TreeNode *> st;
        TreeNode *p;

        if (root == NULL)
            return ret;

        st.push(root);

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            ret.push_back(p->val);

            if (p->right)
                st.push(p->right);

            if (p->left)
                st.push(p->left);
        }

        return ret;
    }
};
