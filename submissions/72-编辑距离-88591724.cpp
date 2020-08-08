/**
 * Submission ID: 88591724
 * Question ID: 72
 * Question Title: 编辑距离
 * Question URL: https://leetcode-cn.com/problems/edit-distance/
 * Solution Time: 2020-07-17 10:18:01
 * Solution Test Result: 1146 / 1146
 * Solution Status: Accepted
 * Solution Memory: 9.1 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), i, j;
        std::vector<std::vector<int> > dp(n1 + 1, std::vector<int>(n2 + 1));

        for (i = 0; i <= n1; ++i)
            dp[i][0] = i;

        for (j = 0; j <= n2; ++j)
            dp[0][j] = j;

        for (i = 1; i <= n1; ++i)
        {
            for (j = 1; j <= n2; ++j)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }
        return dp[n1][n2];
    }
};
