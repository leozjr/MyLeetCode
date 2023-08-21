#include"LeetCodeUtils.h"
/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
            
        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++){
            for (int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        //只有这里和等和子集不一样
        return sum - 2 * dp[target];
    }
};
// @lc code=end

/*
注意这个石头消，并不是真的一个一个去消，而是和等和子集一样，找到尽可能是sum/2的子集，
消除这个子集之后，剩下的就是最优的剩余重量。
*/