/**
 * Submission ID: 87431338
 * Question ID: 43
 * Question Title: 字符串相乘
 * Question URL: https://leetcode-cn.com/problems/multiply-strings/
 * Solution Time: 2020-07-13 17:38:26
 * Solution Test Result: 311 / 311
 * Solution Status: Accepted
 * Solution Memory: 6.6 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        size_t i, j, n, sz1 = num1.size(), sz2 = num2.size();
        std::vector<int> buf(sz1 + sz2, 0);

        for (i = 0; i < sz1; ++i)
        {
            num1[i] -= '0';
        }

        for (i = 0; i < sz2; ++i)
        {
            num2[i] -= '0';
        }

        for (i = 0; i < sz1; ++i)
        {
            for (j = 0; j < sz2; ++j)
            {
                buf[i + j] += num1[sz1 - 1 - i] * num2[sz2 - 1 - j];
            }
        }

        for (i = 0; i < buf.size() - 1; ++i)
        {
            if (buf[i] > 9)
            {
                buf[i + 1] += buf[i] / 10;
                buf[i] %= 10;
            }
        }

        if (buf.back() == 0)
            buf.pop_back();

        n = buf.size();
        std::string ret(n, '\x00');

        for (i = 0; i < n; ++i)
        {
            ret[i] = buf[n - i - 1] + '0';
        }

        return ret;
    }
};
