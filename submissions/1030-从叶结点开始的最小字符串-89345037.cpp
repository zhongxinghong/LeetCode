/**
 * Submission ID: 89345037
 * Question ID: 1030
 * Question Title: 从叶结点开始的最小字符串
 * Question URL: https://leetcode-cn.com/problems/smallest-string-starting-from-leaf/
 * Solution Time: 2020-07-19 16:44:38
 * Solution Test Result: 67 / 67
 * Solution Status: Accepted
 * Solution Memory: 20.2 MB
 * Solution Runtime: 20 ms
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

    void findAllPaths(
        std::vector<std::string> &paths,
        std::string &path,
        TreeNode *root)
    {
        path.push_back(root->val + 'a');

        if (!root->left && !root->right)
        {
            paths.push_back(std::string(path.rbegin(), path.rend()));
        }
        else
        {
            if (root->left)
                findAllPaths(paths, path, root->left);

            if (root->right)
                findAllPaths(paths, path, root->right);
        }

        path.pop_back();
    }

    string smallestFromLeaf(TreeNode* root)
    {
        int i;
        std::vector<std::string> paths;
        std::string path, ret;

        if (root == NULL)
            return ret;

        findAllPaths(paths, path, root);

        for (i = 0; i < paths.size(); ++i)
        {
            if (ret.empty() || paths[i] < ret)
                ret = paths[i];
        }

        return ret;
    }
};
