/**
 * Submission ID: 91031424
 * Question ID: 71
 * Question Title: 简化路径
 * Question URL: https://leetcode-cn.com/problems/simplify-path/
 * Solution Time: 2020-07-24 15:02:27
 * Solution Test Result: 254 / 254
 * Solution Status: Accepted
 * Solution Memory: 7.6 MB
 * Solution Runtime: 12 ms
 */

class Solution {
public:

    string simplifyPath(string path)
    {
        int i = 0, n = path.size();
        std::vector<std::string> v;
        std::string cur, ret;

        for (i = 0; i < n; ++i)
        {
            switch (path[i])
            {
            case '/':
                if (!cur.empty())
                {
                    v.push_back(cur);
                    cur.clear();
                }
                break;

            case '.':
                if (i == n - 1)
                    break;

                if (path[i + 1] == '.' && (i == n - 2 || path[i + 2] == '/'))
                {
                    if (!v.empty())
                        v.pop_back();
                    i++;
                }
                else if (path[i + 1] == '/')
                    break;
                else
                {
                    for (; i < n && path[i] != '/'; ++i)
                        cur.push_back(path[i]);

                    if (i < n)
                        i--;
                }

                break;

            default:
                cur.push_back(path[i]);
                break;
            }
        }

        if (!cur.empty())
            v.push_back(cur);

        ret.push_back('/');

        if (!v.empty())
        {
            for (i = 0; i < v.size() - 1; ++i)
            {
                ret += v[i];
                ret.push_back('/');
            }
            ret += v.back();
        }

        return ret;
    }
};
