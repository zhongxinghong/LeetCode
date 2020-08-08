/**
 * Submission ID: 90697721
 * Question ID: 1160
 * Question Title: 活字印刷
 * Question URL: https://leetcode-cn.com/problems/letter-tile-possibilities/
 * Solution Time: 2020-07-23 15:08:38
 * Solution Test Result: 86 / 86
 * Solution Status: Accepted
 * Solution Memory: 6.1 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    int dfs(std::unordered_map<char, int> &cnt)
    {
        int sum = 0;

        for (auto it = cnt.begin(); it != cnt.end(); ++it)
        {
            if (it->second == 0)
                continue;

            it->second--;
            sum += 1 + dfs(cnt);
            it->second++;
        }

        return sum;
    }

    int numTilePossibilities(string tiles)
    {
        int i, n = tiles.size(), ret = 0;
        std::unordered_map<char, int> cnt;

        for (i = 0; i < n; ++i)
            cnt[tiles[i]]++;

        return dfs(cnt);
    }
};
