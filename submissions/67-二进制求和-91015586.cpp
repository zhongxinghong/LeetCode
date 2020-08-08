/**
 * Submission ID: 91015586
 * Question ID: 67
 * Question Title: 二进制求和
 * Question URL: https://leetcode-cn.com/problems/add-binary/
 * Solution Time: 2020-07-24 14:20:58
 * Solution Test Result: 294 / 294
 * Solution Status: Accepted
 * Solution Memory: 6.7 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:
    string addBinary(string a, string b)
    {
        int n1 = a.size(), n2 = b.size(), n = std::max(n1, n2) + 1, i;
        std::string s(n, 0);

        for (i = 0; i < n1; ++i)
            a[i] -= '0';

        for (i = 0; i < n2; ++i)
            b[i] -= '0';

        for (i = 0; i < n; ++i)
        {
            if (i < n1)
                s[i] += a[n1 - 1 - i];

            if (i < n2)
                s[i] += b[n2 - 1 - i];

            if (s[i] > 1)
            {
                s[i] %= 2;
                s[i + 1] = 1;
            }
        }

        if (s.back() == 0 && n != 1)
        {
            s.pop_back();
            n--;
        }

        for (i = 0; i < n; ++i)
            s[i] += '0';

        return std::string(s.rbegin(), s.rend());
    }
};
