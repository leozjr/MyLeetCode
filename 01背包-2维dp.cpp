#include "LeetCodeUtils.h"

/*
有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
*/

class Solution {
public:
    int bagProblem(vector<int>& weight, vector<int> value, int bag_weight){
        vector<vector<int>> dp(weight.size(), vector<int>(bag_weight+1, 0)); // dp[i][j] 的含义是当容量为 j 时，从 [0,i] 中任意取能装的最大价值

        for (int j = weight[0]; j <= bag_weight; j++) {
                dp[0][j] = value[0];
        }

        for (int i = 1; i < weight.size(); i++) {
            for (int j = 0; j <= bag_weight; j++) {
                if(j < weight[i]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]); 
                }
            }
        }
        printMatrix(dp);

        return dp[weight.size()-1][bag_weight];
    }    
};

int main(){
    Solution s;
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bag_weight = 4;
    cout << s.bagProblem(weight, value, bag_weight) << endl;

    return 0;
}