/**
 * Submission ID: 90691284
 * Question ID: 800
 * Question Title: 字母大小写全排列
 * Question URL: https://leetcode-cn.com/problems/letter-case-permutation/
 * Solution Time: 2020-07-23 14:50:53
 * Solution Test Result: 63 / 63
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    void toggle(char &c)
    {
        static const int d = 'a' - 'A';

        if (islower(c))
            c -= d;
        else
            c += d;
    }

    vector<string> letterCasePermutation(string S)
    {
        int i, j, n = S.size(), m, d, mask;
        std::vector<int> indices;
        std::vector<std::string> ret;
        std::string s;

        for (i = 0; i < n; ++i)
        {
            if (isdigit(S[i]))
                continue;
            indices.push_back(i);
        }

        m = indices.size();
        d = 1 << m;
        ret.resize(d);

        for (mask = 0; mask != d; ++mask)
        {
            s = S;

            for (i = 0, j = 1; i < m; ++i, j <<= 1)
            {
                if (mask & j)
                    continue;
                toggle(s[indices[i]]);
            }

            ret[mask] = s;
        }

        return ret;
    }
};
