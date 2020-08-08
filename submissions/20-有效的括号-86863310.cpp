/**
 * Submission ID: 86863310
 * Question ID: 20
 * Question Title: 有效的括号
 * Question URL: https://leetcode-cn.com/problems/valid-parentheses/
 * Solution Time: 2020-07-11 20:45:31
 * Solution Test Result: 76 / 76
 * Solution Status: Accepted
 * Solution Memory: 6.6 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        for (size_t i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                st.push(s[i]);
                break;

            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;

            default:
                break;
            }
        }

        return st.empty();
    }
};
