/**
 * Submission ID: 86741981
 * Question ID: 6
 * Question Title: Z 字形变换
 * Question URL: https://leetcode-cn.com/problems/zigzag-conversion/
 * Solution Time: 2020-07-11 12:41:07
 * Solution Test Result: 1158 / 1158
 * Solution Status: Accepted
 * Solution Memory: 7.7 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:
    string convert(string s, int numRows) {

        if (s.size() <= 1 || numRows == 1)
            return s;

        std::string ret(s.size(), '\x00');
        int i, j, sz = 0;

        for (i = 0; i < numRows; ++i)
        {
            for (j = i; j < s.size(); )
            {
                if (i != numRows - 1)
                    ret[sz++] = s[j];

                j += 2 * numRows - 2 * (i + 1);

                if (j >= s.size())
                    break;

                if (i != 0)
                    ret[sz++] = s[j];

                j += 2 * i;
            }
        }

        return ret;
    }
};
