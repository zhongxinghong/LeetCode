/**
 * Submission ID: 89603524
 * Question ID: 1116
 * Question Title: 最大层内元素和
 * Question URL: https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/
 * Solution Time: 2020-07-20 14:37:17
 * Solution Test Result: 34 / 34
 * Solution Status: Accepted
 * Solution Memory: 110.1 MB
 * Solution Runtime: 360 ms
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
        int depth;
    };

    int maxLevelSum(TreeNode* root) {
        int depth = 0, sum = 0, mxsum = -1, mxdep = -1;
        std::queue<node_s> q;

        q.push({root, 1});

        for (; !q.empty(); q.pop())
        {
            const auto &ele = q.front();

            if (ele.depth > depth)
            {
                if (sum > mxsum)
                {
                    mxsum = sum;
                    mxdep = depth;
                }

                sum = 0;
                depth++;
            }

            sum += ele.node->val;

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        if (sum > mxsum)
        {
            mxsum = sum;
            mxdep = depth;
        }

        return mxdep;
    }
};
