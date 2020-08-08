/**
 * Submission ID: 86826530
 * Question ID: 13
 * Question Title: 罗马数字转整数
 * Question URL: https://leetcode-cn.com/problems/roman-to-integer/
 * Solution Time: 2020-07-11 17:49:05
 * Solution Test Result: 3999 / 3999
 * Solution Status: Accepted
 * Solution Memory: 6.2 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        size_t i;

        for (i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'I':
                if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    ret -= 1;
                else
                    ret += 1;
                break;
            case 'V':
                ret += 5;
                break;
            case 'X':
                if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    ret -= 10;
                else
                    ret += 10;
                break;
            case 'L':
                ret += 50;
                break;
            case 'C':
                if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    ret -= 100;
                else
                    ret += 100;
                break;
            case 'D':
                ret += 500;
                break;
            case 'M':
                ret += 1000;
                break;
            default:
                break;
            }
        }

        return ret;
    }
};
