/**
 * Submission ID: 91247028
 * Question ID: 91
 * Question Title: 解码方法
 * Question URL: https://leetcode-cn.com/problems/decode-ways/
 * Solution Time: 2020-07-25 11:11:51
 * Solution Test Result: 258 / 258
 * Solution Status: Accepted
 * Solution Memory: 6.5 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    int numDecodings(string s)
    {
        int i, n = s.size();

        if (n == 0 || (n == 1 && s[0] == '0'))
            return 0;

        if (n == 1)
            return 1;

        std::vector<int> dp(n + 1, 0);

        dp[n] = 1;
        dp[n - 1] = (s[n - 1] != '0');

        for (i = n - 2; i > -1; --i)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }

            dp[i] = dp[i + 1];

            if (s[i] <= '1' || (s[i] == '2' && s[i + 1] <= '6'))
                dp[i] += dp[i + 2];
        }

        return dp[0];
    }
};
