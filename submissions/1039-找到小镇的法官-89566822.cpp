/**
 * Submission ID: 89566822
 * Question ID: 1039
 * Question Title: 找到小镇的法官
 * Question URL: https://leetcode-cn.com/problems/find-the-town-judge/
 * Solution Time: 2020-07-20 11:52:48
 * Solution Test Result: 92 / 92
 * Solution Status: Accepted
 * Solution Memory: 60.9 MB
 * Solution Runtime: 412 ms
 */

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        int i, ret = -1;
        std::vector<int> ideg(N, 0), odeg(N, 0);

        for (i = 0; i < trust.size(); ++i)
        {
            odeg[trust[i][0] - 1]++;
            ideg[trust[i][1] - 1]++;
        }

        for (i = 0; i < N; ++i)
        {
            if (ideg[i] != N - 1 || odeg[i] != 0)
                continue;

            if (ret != -1)
                return false;

            ret = i + 1;
        }

        return ret;
    }
};
