/**
 * Submission ID: 89273150
 * Question ID: 394
 * Question Title: 字符串解码
 * Question URL: https://leetcode-cn.com/problems/decode-string/
 * Solution Time: 2020-07-19 12:35:12
 * Solution Test Result: 29 / 29
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 0 ms
 */

class Solution {
public:

    std::string __decodeString(const std::string &s, std::map<int, int> &mp, int st, int ed)
    {
        int i = st, j, cnt;
        std::string ret, tmp;

        while (i < ed)
        {
            if (isdigit(s[i]))
            {
                sscanf(&s[i++], "%d", &cnt);
                while (i < ed && isdigit(s[i]))
                    i++;
                j = mp[i++];
                tmp = __decodeString(s, mp, i, j);
                while (cnt--)
                    ret += tmp;
                i = j + 1;
            }
            else
            {
                ret.push_back(s[i++]);
            }
        }

        return ret;
    }

    string decodeString(string s) {
        int i, j;
        std::map<int, int> mp;
        std::stack<int> st;

        for (i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case '[':
                st.push(i);
                break;
            case ']':
                j = st.top();
                st.pop();
                mp[j] = i;
                break;
            }
        }

        return __decodeString(s, mp, 0, s.size());
    }
};
