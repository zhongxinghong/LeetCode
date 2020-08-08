/**
 * Submission ID: 87429436
 * Question ID: 43
 * Question Title: 字符串相乘
 * Question URL: https://leetcode-cn.com/problems/multiply-strings/
 * Solution Time: 2020-07-13 17:34:49
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

        size_t i, j, sz1 = num1.size(), sz2 = num2.size();
        std::string ret(sz1 + sz2, 0);

        for (i = 0; i < sz1; ++i)
            num1[i] -= '0';

        for (i = 0; i < sz2; ++i)
            num2[i] -= '0';

        for (i = 0; i < sz1; ++i)
        {
            for (j = 0; j < sz2; ++j)
            {
                ret[i + j] += num1[sz1 - 1 - i] * num2[sz2 - 1 - j];
                if (ret[i + j] > 9)
                {
                    ret[i + j + 1] += ret[i + j] / 10;
                    ret[i + j] %= 10;
                }
            }
        }

        if (ret.back() == 0)
            ret.pop_back();

        for (i = 0; i < ret.size(); ++i)
            ret[i] += '0';

        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
