/**
 * Submission ID: 91669812
 * Question ID: 303
 * Question Title: 区域和检索 - 数组不可变
 * Question URL: https://leetcode-cn.com/problems/range-sum-query-immutable/
 * Solution Time: 2020-07-26 19:15:42
 * Solution Test Result: 16 / 16
 * Solution Status: Accepted
 * Solution Memory: 16.7 MB
 * Solution Runtime: 56 ms
 */

class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        int i, n = nums.size();
        cumsum.resize(n + 1);
        cumsum[0] = 0;

        for (i = 0; i < n; ++i)
            cumsum[i + 1] = cumsum[i] + nums[i];
    }

    int sumRange(int i, int j)
    {
        return cumsum[j + 1] - cumsum[i];
    }

private:
    std::vector<int> cumsum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
