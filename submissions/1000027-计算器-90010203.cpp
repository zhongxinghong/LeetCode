/**
 * Submission ID: 90010203
 * Question ID: 1000027
 * Question Title: 计算器
 * Question URL: https://leetcode-cn.com/problems/calculator-lcci/
 * Solution Time: 2020-07-21 16:17:19
 * Solution Test Result: 109 / 109
 * Solution Status: Accepted
 * Solution Memory: 8.7 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:

    void process_op(const char &op, std::stack<int> &st, int &num)
    {
        switch (op)
        {
        case '+':
            st.push(num);
            break;
        case '-':
            st.push(-num);
            break;
        case '*':
            num = st.top() * num;
            st.pop();
            st.push(num);
            break;
        case '/':
            num = st.top() / num;
            st.pop();
            st.push(num);
            break;
        }
    }

    int calculate(string s)
    {
        int i, n = s.size(), num = 0;
        std::stack<int> st;
        char op = '+';

        for (i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
                continue;
            else if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else
            {
                process_op(op, st, num);
                num = 0;
                op = s[i];
            }
        }

        process_op(op, st, num);

        for (num = 0; !st.empty(); st.pop())
            num += st.top();

        return num;
    }
};
