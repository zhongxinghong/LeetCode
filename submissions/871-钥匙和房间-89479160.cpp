/**
 * Submission ID: 89479160
 * Question ID: 871
 * Question Title: 钥匙和房间
 * Question URL: https://leetcode-cn.com/problems/keys-and-rooms/
 * Solution Time: 2020-07-20 01:58:31
 * Solution Test Result: 67 / 67
 * Solution Status: Accepted
 * Solution Memory: 9.9 MB
 * Solution Runtime: 16 ms
 */

class Solution {
public:

    void dfs(
        const std::vector<std::vector<int>> &rooms,
        std::vector<bool> &vis,
        int i)
    {
        if (vis[i])
            return;

        vis[i] = true;

        for (int j = 0; j < rooms[i].size(); ++j)
            dfs(rooms, vis, rooms[i][j]);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = rooms.size(), i;
        std::vector<bool> vis(n, false);

        dfs(rooms, vis, 0);

        for (i = 0; i < n; ++i)
        {
            if (!vis[i])
                return false;
        }

        return true;
    }
};
