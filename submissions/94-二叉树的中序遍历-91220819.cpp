/**
 * Submission ID: 91220819
 * Question ID: 94
 * Question Title: 二叉树的中序遍历
 * Question URL: https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * Solution Time: 2020-07-25 09:50:20
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 7.3 MB
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> ret;
        std::stack<TreeNode *> st;
        TreeNode *p = root, *q;

        while (!st.empty() || p)
        {
            if (p)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                q = st.top();
                st.pop();
                ret.push_back(q->val);
                p = q->right;
            }
        }

        return ret;
    }
};
