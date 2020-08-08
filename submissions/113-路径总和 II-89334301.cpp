/**
 * Submission ID: 89334301
 * Question ID: 113
 * Question Title: 路径总和 II
 * Question URL: https://leetcode-cn.com/problems/path-sum-ii/
 * Solution Time: 2020-07-19 16:15:01
 * Solution Test Result: 114 / 114
 * Solution Status: Accepted
 * Solution Memory: 16.8 MB
 * Solution Runtime: 16 ms
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

    void __pathSum(
        std::vector<std::vector<int>> &ret,
        std::vector<int> &path,
        const TreeNode *root,
        int cumsum,
        const int &sum)
    {
        cumsum += root->val;
        path.push_back(root->val);

        if (!root->left && !root->right)
        {
            if (cumsum == sum)
                ret.push_back(path);
        }
        else
        {
            if (root->left)
                __pathSum(ret, path, root->left, cumsum, sum);

            if (root->right)
                __pathSum(ret, path, root->right, cumsum, sum);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> ret;
        std::vector<int> path;

        if (root == NULL)
            return ret;

        __pathSum(ret, path, root, 0, sum);
        return ret;
    }
};
