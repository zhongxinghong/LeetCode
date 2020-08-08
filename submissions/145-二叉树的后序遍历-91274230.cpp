/**
 * Submission ID: 91274230
 * Question ID: 145
 * Question Title: 二叉树的后序遍历
 * Question URL: https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * Solution Time: 2020-07-25 13:24:15
 * Solution Test Result: 68 / 68
 * Solution Status: Accepted
 * Solution Memory: 8.5 MB
 * Solution Runtime: 4 ms
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

    struct node_s
    {
        TreeNode *node;
        bool visited;
    };

    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> ret;
        std::stack<node_s> st;
        node_s ele;

        if (root == NULL)
            return ret;

        st.push({root, false});

        while (!st.empty())
        {
            auto &ele = st.top();

            if (!ele.visited)
            {
                ele.visited = true;

                if (ele.node->right)
                    st.push({ele.node->right, false});

                if (ele.node->left)
                    st.push({ele.node->left, false});
            }
            else
            {
                ret.push_back(ele.node->val);
                st.pop();
            }
        }

        return ret;
    }
};
