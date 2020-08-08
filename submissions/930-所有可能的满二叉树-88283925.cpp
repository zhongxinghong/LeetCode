/**
 * Submission ID: 88283925
 * Question ID: 930
 * Question Title: 所有可能的满二叉树
 * Question URL: https://leetcode-cn.com/problems/all-possible-full-binary-trees/
 * Solution Time: 2020-07-16 10:38:18
 * Solution Test Result: 20 / 20
 * Solution Status: Accepted
 * Solution Memory: 38.9 MB
 * Solution Runtime: 252 ms
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

    vector<TreeNode*> allPossibleFBT(int N) {
        std::vector<TreeNode *> ret;

        if (N % 2 == 0)
            return ret;

        if (N == 1)
        {
            TreeNode *root = new TreeNode(0);
            ret.push_back(root);
            return ret;
        }

        for (int k = 1; k < N; k += 2)
        {
            auto lFBT = allPossibleFBT(k);
            auto rFBT = allPossibleFBT(N - 1 - k);

            for (size_t i = 0; i < lFBT.size(); ++i)
            {
                for (size_t j = 0; j < rFBT.size(); ++j)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = lFBT[i];
                    root->right = rFBT[j];
                    ret.push_back(root);
                }
            }
        }

        return ret;
    }
};
