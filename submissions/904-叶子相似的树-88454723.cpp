/**
 * Submission ID: 88454723
 * Question ID: 904
 * Question Title: 叶子相似的树
 * Question URL: https://leetcode-cn.com/problems/leaf-similar-trees/
 * Solution Time: 2020-07-16 20:01:26
 * Solution Test Result: 38 / 38
 * Solution Status: Accepted
 * Solution Memory: 11.1 MB
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

    void getLeaves(std::vector<int> &ret, TreeNode *root)
    {
        if (root == NULL)
            return;

        if (!root->left && !root->right)
            ret.push_back(root->val);

        getLeaves(ret, root->left);
        getLeaves(ret, root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> v1, v2;
        getLeaves(v1, root1);
        getLeaves(v2, root2);

        return v1.size() == v2.size() && std::equal(v1.begin(), v1.end(), v2.begin());
    }
};
