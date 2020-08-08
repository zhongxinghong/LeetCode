/**
 * Submission ID: 88325503
 * Question ID: 95
 * Question Title: 不同的二叉搜索树 II
 * Question URL: https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * Solution Time: 2020-07-16 13:07:06
 * Solution Test Result: 9 / 9
 * Solution Status: Accepted
 * Solution Memory: 9.3 MB
 * Solution Runtime: 12 ms
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

    struct CacheItem
    {
        std::vector<TreeNode *> ret;
        bool used;

        CacheItem() : used(false) {}
    };

    std::vector<TreeNode *> &__generateTrees(
        std::vector<std::vector<CacheItem>> &cache, int st, int ed)
    {
        if (cache[st][ed].used)
            return cache[st][ed].ret;

        cache[st][ed].used = true;
        std::vector<TreeNode *> &ret = cache[st][ed].ret;

        if (st > ed)
        {
            ret.push_back(NULL);
            return ret;
        }

        if (st == ed)
        {
            TreeNode *root = new TreeNode(st);
            ret.push_back(root);
            return ret;
        }

        for (int k = st; k <= ed; ++k)
        {
            auto &lBST = __generateTrees(cache, st, k - 1);
            auto &rBST = __generateTrees(cache, k + 1, ed);

            for (int i = 0; i < lBST.size(); ++i)
            {
                for (int j = 0; j < rBST.size(); ++j)
                {
                    TreeNode *root = new TreeNode(k);
                    root->left = lBST[i];
                    root->right = rBST[j];
                    ret.push_back(root);
                }
            }
        }

        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return std::vector<TreeNode *>();

        std::vector<std::vector<CacheItem>> cache(n + 2, std::vector<CacheItem>(n + 2));
        return __generateTrees(cache, 1, n);
    }
};
