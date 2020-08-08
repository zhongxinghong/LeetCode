/**
 * Submission ID: 88287717
 * Question ID: 930
 * Question Title: 所有可能的满二叉树
 * Question URL: https://leetcode-cn.com/problems/all-possible-full-binary-trees/
 * Solution Time: 2020-07-16 10:47:33
 * Solution Test Result: 20 / 20
 * Solution Status: Accepted
 * Solution Memory: 31.5 MB
 * Solution Runtime: 212 ms
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

    struct CacheItem
    {
        std::vector<TreeNode *> ret;
        bool used = false;
    };

    std::vector<TreeNode *> &__allPossibleFBT(std::vector<CacheItem> &cache, int N)
    {
        if (cache[N].used)
            return cache[N].ret;

        cache[N].used = true;
        auto &ret = cache[N].ret;

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
            auto &lFBT = __allPossibleFBT(cache, k);
            auto &rFBT = __allPossibleFBT(cache, N - 1 - k);

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

    vector<TreeNode*> allPossibleFBT(int N) {
        std::vector<CacheItem> cache(N + 1);
        return __allPossibleFBT(cache, N);
    }
};
