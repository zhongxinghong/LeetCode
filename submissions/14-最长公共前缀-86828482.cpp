/**
 * Submission ID: 86828482
 * Question ID: 14
 * Question Title: 最长公共前缀
 * Question URL: https://leetcode-cn.com/problems/longest-common-prefix/
 * Solution Time: 2020-07-11 17:56:41
 * Solution Test Result: 118 / 118
 * Solution Status: Accepted
 * Solution Memory: 6.8 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    size_t min(size_t i, size_t j)
    {
        return i < j ? i : j;
    }

    string longestCommonPrefix(vector<string>& strs) {
        size_t i, j, min_len = -1;
        std::string ret;

        if (strs.empty())
            return ret;

        for (i = 0; i < strs.size(); ++i)
        {
            min_len = min(min_len, strs[i].size());
        }

        for (j = 0; j < min_len; ++j)
        {
            for (i = 0; i < strs.size(); ++i)
            {
                if (strs[i][j] != strs[0][j])
                    return ret;
            }
            ret.push_back(strs[0][j]);
        }

        return ret;
    }
};
