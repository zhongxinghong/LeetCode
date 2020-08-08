/**
 * Submission ID: 90000959
 * Question ID: 1000027
 * Question Title: 计算器
 * Question URL: https://leetcode-cn.com/problems/calculator-lcci/
 * Solution Time: 2020-07-21 15:54:30
 * Solution Test Result: 109 / 109
 * Solution Status: Accepted
 * Solution Memory: 9.6 MB
 * Solution Runtime: 280 ms
 */

class Solution {
public:

    int calculate(string s)
    {
        int i = 0, n = s.size(), x, n1, n2;
        std::deque<int> num;
        std::deque<char> op;

        while (i < n)
        {
            switch (s[i])
            {
            case ' ':
                i++;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
                op.push_back(s[i++]);
                break;

            default:
                sscanf(&s[i++], "%d", &x);
                num.push_back(x);

                while (i < n && isdigit(s[i]))
                    i++;

                if (!op.empty() && (op.back() == '*' || op.back() == '/'))
                {
                    n2 = num.back(); num.pop_back();
                    n1 = num.back(); num.pop_back();
                    num.push_back(op.back() == '*' ?  n1 * n2 : n1 / n2);
                    op.pop_back();
                }

                break;
            }
        }

        for (; !op.empty(); op.pop_front())
        {
            n1 = num.front(); num.pop_front();
            n2 = num.front(); num.pop_front();
            num.push_front(op.front() == '+' ? n1 + n2 : n1 - n2);
        }

        return num.front();
    }
};
