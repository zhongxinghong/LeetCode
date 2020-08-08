/**
 * Submission ID: 89900783
 * Question ID: 1428
 * Question Title: 跳跃游戏 III
 * Question URL: https://leetcode-cn.com/problems/jump-game-iii/
 * Solution Time: 2020-07-21 10:43:38
 * Solution Test Result: 54 / 54
 * Solution Status: Accepted
 * Solution Memory: 26.3 MB
 * Solution Runtime: 92 ms
 */

class Solution {
public:

    bool dfs(
        std::vector<int> &arr,
        std::vector<bool> &vis,
        int i)
    {
        if (i < 0 || i >= arr.size())
            return false;

        if (vis[i])
            return false;

        vis[i] = true;

        if (arr[i] == 0)
            return true;

        if (dfs(arr, vis, i + arr[i]))
            return true;

        if (dfs(arr, vis, i - arr[i]))
            return true;

        return false;
    }

    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        std::vector<bool> vis(n, false);
        return dfs(arr, vis, start);
    }
};
