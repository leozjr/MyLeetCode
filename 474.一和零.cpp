/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include"LeetCodeUtils.h"
// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> cnt(len, vector<int>(2, 0));

        for(int i = 0; i < len; i++){ //计数数组
            for(char c : strs[i]){
                if(c == '0')
                    cnt[i][0]++;
                else
                    cnt[i][1]++;
            }
        }

        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1,  vector<int>(n+1, 0)));

        for(int k = 1; k <= len; k++){
            int zero = cnt[k-1][0]; //第k件物品的统计zero和one的数量是 cnt[k-1]
            int one = cnt[k-1][1];
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n; j++){
                    if(i < zero || j < one){
                        dp[k][i][j] = dp[k-1][i][j];
                    }
                    else{
                        dp[k][i][j] = max(dp[k-1][i][j], dp[k-1][i - zero][j - one] + 1);
                    }
                }
            }
        }

        return dp[len][m][n];

    }
};
// @lc code=end


int main(){
    Solution s;
    vector<string> nums = {"10","0001","111001","1","0"};
    cout << s.findMaxForm(nums, 5,3) << endl;
    return 0;
}

