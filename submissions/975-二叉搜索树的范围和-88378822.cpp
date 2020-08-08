/**
 * Submission ID: 88378822
 * Question ID: 975
 * Question Title: 二叉搜索树的范围和
 * Question URL: https://leetcode-cn.com/problems/range-sum-of-bst/
 * Solution Time: 2020-07-16 16:00:56
 * Solution Test Result: 42 / 42
 * Solution Status: Accepted
 * Solution Memory: 64.9 MB
 * Solution Runtime: 248 ms
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

    struct Node2
    {
        TreeNode *node;
        bool visited;

        Node2(TreeNode *node) : node(node), visited(false) {}
    };

    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        std::stack<Node2> st;

        if (root == NULL)
            return sum;

        st.push(Node2(root));

        while (!st.empty())
        {
            auto ele = st.top();
            st.pop();

            if (!ele.visited)
            {
                ele.visited = true;
                if (ele.node->right)
                    st.push(Node2(ele.node->right));
                st.push(ele);
                if (ele.node->left)
                    st.push(Node2(ele.node->left));
            }
            else
            {
                if (ele.node->val < L)
                    continue;
                if (ele.node->val > R)
                    break;
                sum += ele.node->val;
            }
        }

        return sum;
    }
};
