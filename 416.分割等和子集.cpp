
#include "LeetCodeUtils.h"
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1)
            return false;
            
        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < nums.size(); i++){
            for (int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[target] == target)
            return true;
        else
            return false;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums = {1,2,3,5};
    cout << s.canPartition(nums) << endl;
    return 0;
}