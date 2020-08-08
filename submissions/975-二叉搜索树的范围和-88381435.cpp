/**
 * Submission ID: 88381435
 * Question ID: 975
 * Question Title: 二叉搜索树的范围和
 * Question URL: https://leetcode-cn.com/problems/range-sum-of-bst/
 * Solution Time: 2020-07-16 16:08:25
 * Solution Test Result: 42 / 42
 * Solution Status: Accepted
 * Solution Memory: 64.7 MB
 * Solution Runtime: 232 ms
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

    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        std::stack<TreeNode *> st;
        TreeNode *p;

        if (root == NULL)
            return sum;

        st.push(root);

        while (!st.empty())
        {
            p = st.top();
            st.pop();

            if (p->val >= L && p->val <= R)
                sum += p->val;

            if (p->val > L && p->left)
                st.push(p->left);

            if (p->val < R && p->right)
                st.push(p->right);
        }

        return sum;
    }
};
