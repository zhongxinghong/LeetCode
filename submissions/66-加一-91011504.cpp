/**
 * Submission ID: 91011504
 * Question ID: 66
 * Question Title: 加一
 * Question URL: https://leetcode-cn.com/problems/plus-one/
 * Solution Time: 2020-07-24 14:11:59
 * Solution Test Result: 109 / 109
 * Solution Status: Accepted
 * Solution Memory: 9.3 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, n = digits.size();
        digits[n - 1]++;

        for (i = n - 1; i; --i)
        {
            if (digits[i] != 10)
                break;

            digits[i - 1]++;
            digits[i] = 0;
        }

        if (digits[0] == 10)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
