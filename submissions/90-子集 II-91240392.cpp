/**
 * Submission ID: 91240392
 * Question ID: 90
 * Question Title: 子集 II
 * Question URL: https://leetcode-cn.com/problems/subsets-ii/
 * Solution Time: 2020-07-25 10:49:35
 * Solution Test Result: 19 / 19
 * Solution Status: Accepted
 * Solution Memory: 7.1 MB
 * Solution Runtime: 8 ms
 */

class Solution {
public:

    void dfs(
        std::vector<std::vector<int>> &ret,
        std::vector<int> &tmp,
        std::map<int, int> &cnt)
    {
        ret.push_back(tmp);

        for (auto it = cnt.begin(); it != cnt.end(); ++it)
        {
            if (it->second == 0)
                continue;

            if (!tmp.empty() && tmp.back() > it->first)
                continue;

            it->second--;
            tmp.push_back(it->first);
            dfs(ret, tmp, cnt);
            tmp.pop_back();
            it->second++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        int i, n = nums.size();
        std::map<int, int> cnt;
        std::vector<std::vector<int>> ret;
        std::vector<int> tmp;

        for (i = 0; i < n; ++i)
            cnt[nums[i]]++;

        dfs(ret, tmp, cnt);

        return ret;
    }
};
