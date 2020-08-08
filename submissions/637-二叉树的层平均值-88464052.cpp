/**
 * Submission ID: 88464052
 * Question ID: 637
 * Question Title: 二叉树的层平均值
 * Question URL: https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
 * Solution Time: 2020-07-16 20:28:15
 * Solution Test Result: 65 / 65
 * Solution Status: Accepted
 * Solution Memory: 23.6 MB
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

    struct Node2
    {
        TreeNode *node;
        int depth;
    };

    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ret;
        std::vector<std::vector<int>> v;
        std::queue<Node2> q;

        if (root == NULL)
            return ret;

        q.push({root, 0});

        for (; !q.empty(); q.pop())
        {
            const Node2 &ele = q.front();

            if (ele.depth == v.size())
                v.resize(v.size() + 1);

            v[ele.depth].push_back(ele.node->val);

            if (ele.node->left)
                q.push({ele.node->left, ele.depth + 1});

            if (ele.node->right)
                q.push({ele.node->right, ele.depth + 1});
        }

        ret.resize(v.size());

        for (size_t i = 0; i < v.size(); ++i)
        {
            double sum = 0;
            for (size_t j = 0; j < v[i].size(); ++j)
                sum += v[i][j];
            sum /= v[i].size();
            ret[i] = sum;
        }

        return ret;
    }
};
