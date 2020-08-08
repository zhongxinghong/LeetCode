/**
 * Submission ID: 91256891
 * Question ID: 97
 * Question Title: 交错字符串
 * Question URL: https://leetcode-cn.com/problems/interleaving-string/
 * Solution Time: 2020-07-25 11:47:01
 * Solution Test Result: 101 / 101
 * Solution Status: Accepted
 * Solution Memory: 6.9 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    bool __equal(
        const std::string &s1,
        const std::string &s2,
        int i,
        int j)
    {
        int n1 = s1.size(), n2 = s2.size();

        if (n1 - i != n2 - j)
            return false;

        for (; i < n1; ++i, ++j)
        {
            if (s1[i] != s2[j])
                return false;
        }

        return true;
    }

    bool __isInterleave(
        std::vector<std::vector<int>> &f,
        const std::string &s1,
        const std::string &s2,
        const std::string &s3,
        int i,
        int j,
        int k)
    {
        if (f[i][j] != -1)
            return f[i][j];

        if (i == s1.size())
            return f[i][j] = __equal(s2, s3, j, k);

        if (j == s2.size())
            return f[i][j] = __equal(s1, s3, i, k);

        if (s1[i] != s3[k] && s2[j] != s3[k])
            return f[i][j] = false;

        if (s1[i] == s3[k] && s2[j] != s3[k])
            return f[i][j] = __isInterleave(f, s1, s2, s3, i + 1, j, k + 1);

        if (s1[i] != s3[k] && s2[j] == s3[k])
            return f[i][j] = __isInterleave(f, s1, s2, s3, i, j + 1, k + 1);

        if (s1[i] == s3[k] && s2[j] == s3[k])
            return f[i][j] = __isInterleave(f, s1, s2, s3, i + 1, j, k + 1) ||
                             __isInterleave(f, s1, s2, s3, i, j + 1, k + 1);

        return false;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if (n1 + n2 != n3)
            return false;

        std::vector<std::vector<int>> f(n1 + 1, std::vector<int>(n2 + 1, -1));

        return __isInterleave(f, s1, s2, s3, 0, 0, 0);
    }
};
