/**
 * Submission ID: 89579060
 * Question ID: 1275
 * Question Title: 验证二叉树
 * Question URL: https://leetcode-cn.com/problems/validate-binary-tree-nodes/
 * Solution Time: 2020-07-20 12:51:57
 * Solution Test Result: 36 / 36
 * Solution Status: Accepted
 * Solution Memory: 32.5 MB
 * Solution Runtime: 96 ms
 */

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int i;
        std::vector<int> ideg(n, 0), odeg(n, 0);
        bool found_root = false;

        for (i = 0; i < n; ++i)
        {
            if (leftChild[i] != -1)
            {
                odeg[i]++;
                ideg[leftChild[i]]++;
            }

            if (rightChild[i] != -1)
            {
                odeg[i]++;
                ideg[rightChild[i]]++;
            }
        }

        for (i = 0; i < n; ++i)
        {
            if (ideg[i] == 0)
            {
                if (odeg[i] == 0 && n > 1)
                    return false;

                if (found_root)
                    return false;

                found_root = true;
                continue;
            }

            if (ideg[i] > 1)
                return false;
        }

        return found_root;
    }
};
