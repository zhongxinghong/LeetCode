/**
 * Submission ID: 88366518
 * Question ID: 257
 * Question Title: 二叉树的所有路径
 * Question URL: https://leetcode-cn.com/problems/binary-tree-paths/
 * Solution Time: 2020-07-16 15:31:26
 * Solution Test Result: 209 / 209
 * Solution Status: Accepted
 * Solution Memory: 13.3 MB
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

    void __binaryTreePaths(std::vector<std::string> &ret, std::vector<TreeNode *> &path)
    {
        if (!path.back()->left && !path.back()->right)
        {
            std::string s;
            for (size_t i = 0; i < path.size() - 1; ++i)
                s += std::to_string(path[i]->val) + "->";
            s += std::to_string(path.back()->val);
            ret.push_back(s);
            return;
        }

        if (path.back()->left)
        {
            path.push_back(path.back()->left);
            __binaryTreePaths(ret, path);
            path.pop_back();
        }

        if (path.back()->right)
        {
            path.push_back(path.back()->right);
            __binaryTreePaths(ret, path);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        std::vector<TreeNode *> path;

        if (root == NULL)
            return ret;

        path.push_back(root);

        __binaryTreePaths(ret, path);
        return ret;
    }
};
