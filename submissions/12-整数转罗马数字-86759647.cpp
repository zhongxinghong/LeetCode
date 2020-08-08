/**
 * Submission ID: 86759647
 * Question ID: 12
 * Question Title: 整数转罗马数字
 * Question URL: https://leetcode-cn.com/problems/integer-to-roman/
 * Solution Time: 2020-07-11 14:21:55
 * Solution Test Result: 3999 / 3999
 * Solution Status: Accepted
 * Solution Memory: 7.8 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:

    struct Rule
    {
        int bound;
        const char *str;
    };

    std::vector<Rule> rules = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    string intToRoman(int num) {
        std::string ret;
        size_t i;

        while (num > 0)
        {
            for (i = 0; i < rules.size(); ++i)
            {
                if (num < rules[i].bound)
                    continue;
                ret += rules[i].str;
                num -= rules[i].bound;
                break;
            }
        }

        return ret;
    }
};
