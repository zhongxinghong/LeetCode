/**
 * Submission ID: 86751339
 * Question ID: 8
 * Question Title: 字符串转换整数 (atoi)
 * Question URL: https://leetcode-cn.com/problems/string-to-integer-atoi/
 * Solution Time: 2020-07-11 13:37:56
 * Solution Test Result: 1079 / 1079
 * Solution Status: Accepted
 * Solution Memory: 6.2 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:

    bool isNumber(const char &c)
    {
        return c >= '0' && c <= '9';
    }

    bool isValidChar(const char &c)
    {
        return isNumber(c) || c == '+' || c == '-' || c == '.';
    }

    int myAtoi(string str) {
        size_t i;
        bool lt0 = false;
        double ret = 0;

        for (i = 0; i < str.size() && str[i] == ' '; ++i)
            ;;

        if (str[i] == '+' || str[i] == '-')
        {
            lt0 = (str[i++] == '-');
        }
        else if (!isNumber(str[i]))
        {
            return 0;
        }

        for (; i < str.size(); ++i)
        {
            if (str[i] == '.' || !isNumber(str[i]))
                break;

            ret = 10 * ret + (str[i] - '0');
        }

        if (lt0)
            ret = -ret;

        if (ret > INT_MAX)
            return INT_MAX;

        if (ret < INT_MIN)
            return INT_MIN;

        return ret;
    }
};
