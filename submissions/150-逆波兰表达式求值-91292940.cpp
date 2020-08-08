/**
 * Submission ID: 91292940
 * Question ID: 150
 * Question Title: 逆波兰表达式求值
 * Question URL: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * Solution Time: 2020-07-25 14:59:34
 * Solution Test Result: 20 / 20
 * Solution Status: Accepted
 * Solution Memory: 10.6 MB
 * Solution Runtime: 24 ms
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int i, n = tokens.size(), x, n1, n2;
        std::stack<int> st;

        for (i = 0; i < n; ++i)
        {
            if (tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/")
            {
                sscanf(&tokens[i][0], "%d", &x);
                st.push(x);
            }
            else
            {
                n2 = st.top(); st.pop();
                n1 = st.top(); st.pop();

                switch (tokens[i][0])
                {
                case '+': st.push(n1 + n2); break;
                case '-': st.push(n1 - n2); break;
                case '*': st.push(n1 * n2); break;
                case '/': st.push(n1 / n2); break;
                }
            }
        }

        return st.top();
    }
};
