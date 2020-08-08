/**
 * Submission ID: 88158252
 * Question ID: 173
 * Question Title: 二叉搜索树迭代器
 * Question URL: https://leetcode-cn.com/problems/binary-search-tree-iterator/
 * Solution Time: 2020-07-15 20:55:29
 * Solution Test Result: 62 / 62
 * Solution Status: Accepted
 * Solution Memory: 26.3 MB
 * Solution Runtime: 124 ms
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *node = st.top();
        int ret = node->val;

        st.pop();

        if (node->right)
        {
            node = node->right;

            while (node)
            {
                st.push(node);
                node = node->left;
            }
        }

        return ret;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }

private:
    std::stack<TreeNode *> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
