/**
 * Submission ID: 90998015
 * Question ID: 60
 * Question Title: 第k个排列
 * Question URL: https://leetcode-cn.com/problems/permutation-sequence/
 * Solution Time: 2020-07-24 13:03:07
 * Solution Test Result: 200 / 200
 * Solution Status: Accepted
 * Solution Memory: 6.2 MB
 * Solution Runtime: 4 ms
 */

class Solution {
public:

    void __getPermutation(std::vector<int> &v, std::string &ret, int s, int k)
    {
        if (v.empty())
            return;

        int i, n;

        n = v.size();
        s /= n;
        i = (k - 1) / s;

        ret.push_back(v[i] + '0');

        v.erase(v.begin() + i);
        k = (k % s == 0) ? s : k % s;

        __getPermutation(v, ret, s, k);
    }

    string getPermutation(int n, int k)
    {
        int i, s = 1;
        std::vector<int> v(n);
        std::string ret;

        for (i = 1; i <= n; ++i)
        {
            v[i - 1] = i;
            s *= i;
        }

        __getPermutation(v, ret, s, k);

        return ret;
    }
};
