/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sum_target = (sum + target) / 2;
        if((sum + target) % 2 == 1 || abs(target) > sum)
            return 0;

        vector<int> dp(sum_target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            for (int j = sum_target; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[sum_target];
    }
};
// @lc code=end

