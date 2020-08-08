/**
 * Submission ID: 88317479
 * Question ID: 652
 * Question Title: 寻找重复的子树
 * Question URL: https://leetcode-cn.com/problems/find-duplicate-subtrees/
 * Solution Time: 2020-07-16 12:14:05
 * Solution Test Result: 169 / 169
 * Solution Status: Accepted
 * Solution Memory: 49.5 MB
 * Solution Runtime: 56 ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    std::string __findDuplicateSubtrees(
        std::vector<TreeNode *> &ret,
        std::unordered_map<std::string, int> &mp,
        TreeNode *root)
    {
        if (root == NULL)
            return "#,";

        std::string s = std::to_string(root->val) + "," +
                        __findDuplicateSubtrees(ret, mp, root->left) +
                        __findDuplicateSubtrees(ret, mp, root->right);

        switch (mp[s])
        {
        case 0:
            mp[s]++;
            break;
        case 1:
            mp[s]++;
            ret.push_back(root);
            break;
        default:
            break;
        }

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::vector<TreeNode *> ret;
        std::unordered_map<std::string, int> mp;
        __findDuplicateSubtrees(ret, mp, root);
        return ret;
    }
};
