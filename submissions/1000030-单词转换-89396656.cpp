/**
 * Submission ID: 89396656
 * Question ID: 1000030
 * Question Title: 单词转换
 * Question URL: https://leetcode-cn.com/problems/word-transformer-lcci/
 * Solution Time: 2020-07-19 20:01:26
 * Solution Test Result: 39 / 39
 * Solution Status: Accepted
 * Solution Memory: 15.5 MB
 * Solution Runtime: 956 ms
 */

class Solution {
public:

    bool findPath(
        const std::vector<std::vector<int>> &g,
        std::vector<bool> &vis,
        int st,
        int ed,
        std::vector<int> &path)
    {
        int i, j;

        path.push_back(st);
        vis[st] = true;

        if (st == ed)
            return true;

        for (i = 0; i < g[st].size(); ++i)
        {
            j = g[st][i];

            if (vis[j])
                continue;

            if (findPath(g, vis, j, ed, path))
                return true;
        }

        path.pop_back();
        return false;
    }


    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        wordList.push_back(beginWord);

        int n = wordList.size(), m = beginWord.size(), begin_ix = n - 1, end_ix = -1, i, j, k;
        bool found_diff;
        std::vector<std::string> ret;
        std::vector<int> path;
        std::vector<std::vector<int>> g(n);
        std::vector<bool> vis(n);

        for (i = 0; i < n && end_ix == -1; ++i)
        {
            if (end_ix == -1 && wordList[i] == endWord)
                end_ix = i;
        }

        if (end_ix == -1)
            return ret;

        for (i = 0; i < n - 1; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                found_diff = false;

                for (k = 0; k < m; ++k)
                {
                    if (wordList[i][k] != wordList[j][k])
                    {
                        if (!found_diff)
                            found_diff = true;
                        else
                            goto CONTINUE_J;
                    }
                }

                if (!found_diff)
                    continue;

                g[i].push_back(j);
                g[j].push_back(i);

            CONTINUE_J:
                continue;
            }
        }

        findPath(g, vis, begin_ix, end_ix, path);

        for (i = 0; i < path.size(); ++i)
            ret.push_back(wordList[path[i]]);

        return ret;
    }
};
